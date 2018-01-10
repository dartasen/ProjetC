#include "lib/lib.h"

Ouvrage** chargeFouvrage(FILE* fichier, int* nbO) {
	Ouvrage **tab, **newtab;
	int i = 0;

	fscanf(fichier, "%d%*c", nbO);

	tab = (Ouvrage**) malloc(*nbO * sizeof(Ouvrage*));

	if (tab == NULL) {
		printf("Erreur de malloc du tableau ouvrage \n");
		free(tab);
		exit(1);
	}

	while (!feof(fichier)) {
		if (i > (*nbO - 1)) {
		 	printf("Une erreur est survenue, le nombre déclaré en tête de fichier a été dépassé lors du parcourement de fichier\n");
			break;
		}
		
		if (i == *nbO) {
			newtab = (Ouvrage**) realloc(tab, (*nbO + 1) * sizeof(Ouvrage*));

			if (newtab != NULL) {
				tab = newtab;
				free(newtab);
			} else {
				printf("Erreur de ralloc du tab ouvrage \n");
				free(newtab);
				exit(1);
			}
			
			*nbO += 1;
		}

		tab[i] = (Ouvrage*) malloc(sizeof(Ouvrage));

		if (tab[i] == NULL) {
			printf("Erreur de malloc d'un ouvrage \n");
			exit(1);
		}

		*tab[i] = lireOuvrage(fichier);
		i++;
	}

	return tab;
}

void sauvegarde(Ouvrage* tabO[], Lecteur* tabL[], int nbO, int nbL) {
	int etat = 0;

	etat += sauvegardeOuvrage(tabO, nbO);
	etat += sauvegardeLecteur(tabL, nbL);

	if (etat < 0)
		exit(1);

	printf("\nSAUVEGARDE EFFECTUEE !\n");
}

void streplace(char mot[], char remplacer, char remplacant) {
	int i;

	for (i = 0; mot[i] != '\0'; i++)
		if (mot[i] == remplacer)
			mot[i] = remplacant;
}

int sauvegardeOuvrage(Ouvrage* tab[], int nbr) {
	FILE* fichier = fopen("ouvrage.don", "w");
	Ouvrage m;
	int i;

	if (fichier == NULL) {
		printf("Erreur lors de l'ouverture du fichier ouvrage.don \n");
		fclose(fichier);
		
		return -1;
	}

	fprintf(fichier, "%d", nbr);

	for (i = 0; i < nbr; i++) {
		m = *tab[i];
		
		streplace(m.titre, ' ', '~');
		streplace(m.categorie, ' ', '~');

		fprintf(fichier, "\n%s %s %d %s %d ", m.cote, m.titre, m.quantite, m.categorie, m.quantiteEmprunt);
		ecrireMotClef(fichier, m.motclefs);
	}

	fclose(fichier);

	return 1;
}

int sauvegardeLecteur(Lecteur* tab[], int nbLecteur) {
	FILE* flot = fopen("lecteur.don", "wb");
	int i;

	if (flot == NULL) {
		printf("Erreur lors de l'ouverture du fichier lecteur.don \n");
		fclose(flot);

		return -1;
	}
	
	fwrite(&nbLecteur,sizeof(int),1,flot);
	
	for (i=0; i<nbLecteur; i++){
		fwrite(tab[i],sizeof(Lecteur),1,flot);
		sauvegardeBinEmprunt(tab[i]->emprunt,tab[i]->nbEmprunt,flot);
	}

	fclose(flot);

	return 1;
}

void sauvegardeBinEmprunt(Emprunt le, int nbEmprunt, FILE *flot) {
	if (le == NULL)
		return;

	if (le->suiv == NULL) {
		fwrite(&le,sizeof(Emprunt),1,flot);
		return;
	}

	fwrite(&le,sizeof(Emprunt),1,flot);
	sauvegardeBinEmprunt(le->suiv,nbEmprunt-1,flot);
}

Emprunt chargerBinEmprunt(FILE *flot, int nbElem) {
		int i;
		Emprunt l = NULL, l2 = NULL;

		printf("%d",nbElem);

		for (i=0; i<nbElem;i++) {
			fread(&l2, sizeof(Emprunt),1,flot);
			l=insererEnTeteEmpruntBin(l, l2->cote,l2->date);
		}

		return l;
}

Lecteur ** chargementBinLecteur(FILE *flot) {
	int i,nbLecteur;
	Lecteur **tab;

	nbLecteur = fread(&nbLecteur,sizeof(int),1,flot);
	tab = (Lecteur **) malloc(sizeof(Lecteur *));
	for (i=0; i<nbLecteur; i++)
	{
		tab[i]= (Lecteur *)malloc(sizeof(Lecteur));
		fread(tab[i],sizeof(Lecteur),1,flot);
		tab[i]->emprunt=chargerBinEmprunt(flot,tab[i]->nbEmprunt);
	}
	return tab;
}

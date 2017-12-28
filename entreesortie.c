#include "lib/lib.h"

Ouvrage** chargeFouvrage(FILE* fichier, int* nbO) {
	Ouvrage **tab, **newtab, o;
	int i = 0;

	fscanf(fichier, "%d", nbO);

	tab = (Ouvrage**) malloc(*nbO * sizeof(Ouvrage*));
	tab[0] = (Ouvrage*) malloc(sizeof(Ouvrage));

	if (tab == NULL || tab[0] == NULL) {
		printf("Erreur de malloc du tableau ouvrage \n");
		free(tab);
		exit(1);
	}

	o = lireOuvrage(fichier);

	while (!feof(fichier)) {
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
		}

		tab[i] = (Ouvrage*) malloc(sizeof(Ouvrage));

		if (tab[i] == NULL) {
			printf("Erreur de malloc d'un ouvrage \n");
			exit(1);
		}

		*tab[i] = o;
		*nbO += 1;
		i++;

		o = lireOuvrage(fichier);
	}

	return tab;
}

Ouvrage** ajouterOuvrage(Ouvrage** tab, int* nbO, Ouvrage o) {
	Ouvrage **aux;

	aux = (Ouvrage**) realloc(tab, (*nbO + 1) * sizeof(Ouvrage*));

	if (aux == NULL) {
		printf("Erreur de ralloc du tab ouvrage \n");
		free(aux);
		exit(1);
	}

	aux[*nbO] = (Ouvrage*) malloc(sizeof(Ouvrage));

	if (aux[*nbO] == NULL) {
		printf("Erreur de malloc d'un ouvrage \n");
		exit(1);
	}

	*aux[*nbO] = o;
	*nbO += 1;

	return aux;
}

void sauvegarde(Ouvrage* tabO[], Lecteur* tabL[], int nbO, int nbL) {
	int etat = 0;

	etat += sauvegardeOuvrage(tabO, nbO);
	etat += sauvegardeLecteur(tabL, nbL);

	if (etat < 0)
		exit(1);

	printf("\nSAUVEGARDE EFFECTUEE !\n");
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

	fprintf(fichier, "%d\n", nbr);

	for (i = 0; i < nbr; i++) {
		m = *tab[i];

		fprintf(fichier, "%s\t%d\t%s\t%d\t%s\t", m.cote, m.quantite, m.titre, m.quantiteEmprunt, m.categorie);
		ecrireMotClef(fichier, m.motclefs);
	}

	fclose(fichier);

	return 1;
}

int sauvegardeLecteur(Lecteur* tab[], int nbr) {
	FILE* fichier = fopen("lecteur.don", "w");

	if (fichier == NULL) {
		printf("Erreur lors de l'ouverture du fichier lecteur.don \n");
		fclose(fichier);

		return -1;
	}

	fclose(fichier);

	return 1;
}

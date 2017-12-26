#include "lib/lib.h"

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

		fprintf(fichier, "%s\t%s\t%s\t%d\t%d\t", m.cote, m.titre, m.categorie, m.quantite, m.quantiteEmprunt);
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

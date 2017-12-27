#include "lib/lib.h"

Ouvrage saisirOuvrage(void) {
	MotClef m = MotVide();
	char c[20];
	Ouvrage o;

	printf("\nSaisir la côte de l'ouvrage \n");
	scanf("%s%*c", o.cote);

	printf("Saisir le titre du livre \n");
	fgets(o.titre, sizeof(o.titre), stdin);
	o.titre[strlen(o.titre) - 1] = '\0';

	printf("Saisir le nom de la catégorie \n");
	fgets(o.categorie, sizeof(o.categorie), stdin);
	o.categorie[strlen(o.categorie) - 1] = '\0';

	printf("Saisir la quantité de livre \n");
	scanf("%d", &o.quantite);

	m = (MotClef) malloc(sizeof(MaillonMot));

	if (m == NULL) {
		printf("Erreur de malloc des MotClefs \n");
		exit(1);
	}

	printf("Saisir les mot-clefs non composés du livre (:q pour quitter) \n");

	while (strcmp(c, ":q") != 0) {
		printf("Saisie > ");
		scanf("%s", c);
		insererMotClef(m, c);
	}

	o.quantiteEmprunt = 0;
	o.motclefs = m;

	return o;
}

void afficherOuvrage(Ouvrage o) {
	printf("%s \n", o.titre);
	printf("> Côte : %s \n", o.cote);
	printf("> Catégorie : %s \n", o.categorie);
	printf("> Quantité : %d (- %d) \n", o.quantite, o.quantiteEmprunt);
	afficherMotClef(o.motclefs);

	printf("\n");
}

Ouvrage lireOuvrage(FILE* fichier) {
	char serial[100] = "VIDE";
	Ouvrage o;

	fscanf(fichier, "%s%*c", o.cote);
	fgets(o.titre, sizeof(o.titre), fichier);
	fscanf(fichier, "%d%*c", &o.quantite);
	fgets(o.categorie, sizeof(o.categorie), fichier);
	fscanf(fichier, "%d%*c", &o.quantiteEmprunt);
	fscanf(fichier, "%s", serial);

	o.motclefs = lireMotClef(serial);

	return o;
}

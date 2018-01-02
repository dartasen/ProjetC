#include "lib/lib.h"

Ouvrage saisirOuvrage(void) {
	MotClef m = NULL;
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
	scanf("%d%*c", &o.quantite);
	
	while (o.quantite < 0) {
		printf("! Une quantité ne peut-être négative ! \n");
		printf("Saisir la quantitÃ© de livre \n");
		scanf("%d%*c", &o.quantite);
	}

	m = (MaillonMot*) malloc(sizeof(MaillonMot));

	if (m == NULL) {
		printf("Erreur de malloc des MotClefs \n");
		exit(1);
	}

	printf("Saisir les mot-clefs non composés du livre (:q pour quitter) \n");
	printf("Saisie > ");
	
	scanf("%s%*c", c);
	strcpy(m->mot, c);
	m->suiv = NULL;

	while (strcmp(c, ":q") != 0) {
		printf("Saisie > ");
		scanf("%s%*c", c);
		insererMotClef(m, c);
	}
	
	if (longueurMotClef(m) == 1)
		strcpy(m->mot, "AUCUN");

	o.quantiteEmprunt = 0;
	o.motclefs = m;
	
	printf("\n");

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
	char temp[35], temp2[20];
	Ouvrage o;

	fscanf(fichier, "%s %s %d %s %d %s", o.cote, temp, &o.quantite, temp2, &o.quantiteEmprunt, serial);

	streplace(temp, ':', ' ');
	strcpy(o.titre, temp);
	streplace(temp2, ':', ' ');
	strcpy(o.categorie, temp2);

	o.motclefs = lireMotClef(serial);

	return o;
}

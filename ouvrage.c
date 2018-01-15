#include "lib/lib.h"

Ouvrage saisirOuvrage(void) {
	MotClef m = NULL;
	char c[20];
	Ouvrage o;

	printf("\nSaisir la côte de l'ouvrage (non composée)\n");
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
		printf("! Une quantité ne peut-Ãªtre négative ! \n");
		printf("Saisir la quantité de livre \n");
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

	if (longueurMotClef(m) == 1 && strcmp(c,":q") != 0)
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
	char serial[100] = "AUCUN";
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

Ouvrage** ajouterOuvrage(Ouvrage** tab, int* nbO, Ouvrage o) {
	int i = rechercherOuvrage(o.cote, tab, *nbO);
	Ouvrage **aux;

	if (i != -1) {
		printf("Impossible d'ajouter cette ouvrage car il existe déjà !\n");
		return tab;
	}

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

int rechercherOuvrage(char *cote, Ouvrage* tabO[], int nbO) {
    int deb = 0, fin = nbO - 1 , m;

    while(deb <=fin) {
        m = (fin+deb)/2;

        if (strcmp(cote,tabO[m]->cote) == 0)
            return m;

        if (strcmp(cote,tabO[m]->cote) < 0)
            fin = m - 1;
        else
        	deb = m + 1;
    }

    return -1;
}

Ouvrage** supprimerOuvrage(Ouvrage* tabO[], int* nbO, int i) {
	Ouvrage** aux;
	int j;

	free(tabO[i]);

	for (j = i; j <= *nbO-1; j++)
		tabO[j] = tabO[j+1];

	*nbO -= 1;

	aux = (Ouvrage**) realloc(tabO, (*nbO) * sizeof(Ouvrage*));

	if (aux == NULL && *nbO > 0) {
		printf("Erreur de ralloc du tab ouvrage \n");
		free(aux);
		exit(1);
	}

	return aux;
}

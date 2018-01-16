#include "lib/lib.h"

Lecteur saisirLecteur(void) {
  Emprunt m = EmpruntVide();
  Lecteur l;

  printf("Saisissez le numéro du lecteur :\n");
  scanf("%d%*c", &l.numLecteur);

  printf("Saisir le nom du lecteur \n");
  fgets(l.nom, sizeof(l.nom), stdin);
  l.nom[strlen(l.nom) - 1] = '\0';

  printf("Saisir le prénom du lecteur \n");
  fgets(l.prenom, sizeof(l.prenom), stdin);
  l.prenom[strlen(l.prenom) - 1] = '\0';
	
  l.emprunt = m;

return l;
}

void afficheLecteur(Lecteur l) {
	printf("> Lecteur n° %d\n", l.numLecteur);
	printf("> Nom : %s\n", l.nom);
	printf("> Prénom : %s\n", l.prenom);
	afficherEmprunt(l.emprunt);

	printf("\n");
}

int comparerNomPrenom(char* nom, char* prenom, char* nom1, char* prenom1) {
	int comp = strcmp(nom, nom1);
	int comp2 = strcmp(prenom, prenom1);

	if (comp == 0)
		return comp2;

	return comp;
}

void trierEchange(Lecteur* tab[], int nb) {
	int pge;

	while (nb > 1) {
		pge = rechercheEchange(tab, nb);
		echangerEchange(tab, pge, nb -1);
		nb --;
	}
}

void echangerEchange(Lecteur* tab[], int i, int j) {
	Lecteur* aux;

	aux = tab[i];
	tab[i] = tab[j];
	tab[j] = aux;
}

int rechercheEchange(Lecteur* tab[], int nb) {
	int pge = 0, i;

	for (i=1; i < nb; i++)

		if (comparerNomPrenom(tab[i]->nom, tab[i]->prenom, tab[pge]->nom, tab[pge]->prenom) > 0)
			pge = i;

	return pge;
}

int rechercheLecteur(int numeroLecteur, Lecteur **tabl, int nb) {
    int deb = 0,fin = nb - 1, m;

    while(deb <=fin) {
        m = (fin + deb) / 2;

        if (tabl[m]->numLecteur == numeroLecteur)
            return m;

        if (tabl[m]->numLecteur<numeroLecteur)
            fin = m - 1;
        else
        	deb = m + 1;
    }

    return -1;
}

Lecteur** ajouterLecteur(Lecteur* tabL[], int* nbL, Lecteur l) {
	int i = rechercheLecteur(l.numLecteur, tabL, *nbL);
	Lecteur **aux;

	if (i != -1) {
		printf("Impossible d'ajouter ce lecteur car il existe déjà !\n");
		return tabL;
	}

	aux = (Lecteur**) realloc(tabL, (*nbL +1) * sizeof(Lecteur*));
	
	if (aux == NULL) {
		printf("erreur de malloc dans ajouterLecteur\n");
		free(aux);
		exit(1);
	}
	
	aux[*nbL] = (Lecteur*) malloc(sizeof(Lecteur));

	if (aux[*nbL] == NULL) {
			printf("Erreur de malloc dans ajouterLecteur \n");
			exit(1);
	}

	*aux[*nbL] = l;
	*nbL += 1;

	return aux;
}

Lecteur** supprimerLecteur(Lecteur* tabL[], int* nbL, int i) {
	Lecteur** aux;
	int j;

	free(tabL[i]);

	for (j = i; j <= *nbL-1; j++)
		tabL[j] = tabL[j+1];

	*nbL -= 1;

	aux = (Lecteur**) realloc(tabL, (*nbL) * sizeof(Lecteur*));

	if (aux == NULL && *nbL > 0) {
		printf("Erreur de re alloc dans supprimerLecteur \n");
		free(aux);
		exit(1);
	}

	return aux;
}

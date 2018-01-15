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

int comparerNomPrenom(char* nom, char* prenom, char* nom1, char* prenom1) {
	int comp = strcmp(nom, nom1);
	int comp2 = strcmp(prenom, prenom1);
	
	if (comp == 0)
		return comp2;
	
	return comp;
}

void DecalerADroite(Lecteur* tab[], int n, int i) {
	int j;
	
	for (j = n-1; j >= i; j--)
		tab[j+1] = tab[j];
}

void DecalerAGauche(Lecteur* tab[], int n, int i) {
	int j;
	
	for (j = i; j <= n-1; j++)
		tab[j] = tab[j+1];
}


Lecteur** ajouterLecteur(Lecteur* tabL[], int* nbL, Lecteur l) {
	Lecteur *aux;
	aux = (Lecteur*)malloc(sizeof(Lecteur)*(*nbL) + 1);
	
	if( aux == NULL)
		{
		printf("erreur de malloc dans ajouterLecteur\n");
		exit(1);
		}
	
	aux = *tabL;
	aux[*nbL + 1] = l;
	return aux;
}

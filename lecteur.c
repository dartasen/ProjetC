#include "lib/lib.h"

Lecteur saisirLecteur(void) {  
  Lecteur l;

  printf("Saisissez le numéro du lecteur :\n");
  scanf("%d%*c", &l.numLecteur);

  printf("Saisir le nom du lecteur \n");
  fgets(l.nom, sizeof(l.nom), stdin);
  l.nom[strlen(l.nom) - 1] = '\0';

  printf("Saisir le prénom du lecteur \n");
  fgets(l.prenom, sizeof(l.prenom), stdin);
  l.prenom[strlen(l.prenom) - 1] = '\0';
	
  l.emprunt = NULL;

return l;
}

void afficheLecteur(Lecteur l) {
	printf("\n///////////////////////////\n");

	printf("Lecteur n° %d\n", l.numLecteur);
	printf("Nom : %s\n", l.nom);
	printf("Prénom : %s\n", l.prenom);

	printf("///////////////////////////\n\n");
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

Lecteur saisirLecteur(void) {  
  Lecteur l;

  printf("Saisissez le numéro du lecteur :\n");
  scanf("%d%*c", &l.numLecteur);

  printf("Saisir le nom du lecteur \n");
  fgets(l.nom, sizeof(l.nom), stdin);
  l.nom[strlen(l.nom) - 1] = '\0';

  printf("Saisir le prénom du lecteur \n");
  fgets(l.prenom, sizeof(l.prenom), stdin);
  l.prenom[strlen(l.prenom) - 1] = '\0'
	  
  l.emprunt = NULL;

return l;
}

void afficheLecteur(Lecteur l){

	printf("\n///////////////////////////\n");

	printf("Lecteur n° %d\n", l.numLecteur);
	printf("Nom : %s\n", l.nom);
	printf("Prénom : %s\n", l.prenom);

	printf("///////////////////////////\n\n");
}

void DecalerADroite(Lecteur **l, int n, int i) {
	int j;
	
	for (j = n-1; j >= i; j--)
		l[j+1] = l[j];
}

void DecalerAGauche(Lecteur **l, int n, int i) {
	int j;
	
	for( j = i; j <= n-1; j++)
		l[j] = l[j+1];
}

int ajouterLecteur(Lecteur **tab, Lecteur l, int nbelem, int tmax) {
	int i;
	
	if(nbelem == tmax) {
		printf("Erreur, tableau de Lecteur plein");
		return -1;
	}

	DecalerADroite(tab,nbelem,i);
	tab[i] = l;
	
	return nbelem +1 ;
}

int supprimerLecteur(Lecteur **tab, int i, int nbelem) {
	
	if(nbelem == 0) {
		printf("Tableau deja vide");
		return -1;
	}
	
	DecalerAGauche(tab,nbelem,i);
	
	return nbelem -1 ;
}

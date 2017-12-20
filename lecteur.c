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

int rechercheEchange(Lecteur* tab[], int nb) {
	int pge = 0, i;

	for (i=1; i < nb; i++)

		if (comparerNomPrenom(tab[i]->nom, tab[i]->prenom, tab[pge]->nom, tab[pge]->prenom) > 0)
			pge = i;

	return pge;
}

int comparerNomPrenom(char* nom, char* prenom, char* nom1, char* prenom1) {

	if (strcmp(nom, nom1) > 0) {
		
	}


	return -1;
}

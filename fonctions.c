#include "lib/lib.h"

Lecteur saisirLecteur(void) {
  
  Lecteur l;

  printf("Saisissez le numéro du lecteur : ");
  scanf("%d", &l.numLecteur);

  printf("Saisissez le nom du lecteur : ");
  scanf("%s", l.nom);
  
  printf("Saisissez le prénom du lecteur : ");
  scanf("%s", l.prenom);
        
  l.emprunt = NULL;
}

void afficheLecteur(Lecteur l){

	printf("///////////////////////////\n");

	printf("Lecteur n° %d\n", l.numLecteur);
	printf("Nom : %s\n", l.nom);
	printf("Prénom : %s\n", l.prenom);

	printf("///////////////////////////\n");
}

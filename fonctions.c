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

void afficheLecteur(Lecteur l){

	printf("\n///////////////////////////\n");

	printf("Lecteur n° %d\n", l.numLecteur);
	printf("Nom : %s\n", l.nom);
	printf("Prénom : %s\n", l.prenom);

	printf("///////////////////////////\n\n");
}

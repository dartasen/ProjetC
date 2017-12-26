#include "lib/lib.h"

void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL) {
 int choix = 0;
 Ouvrage o;
 Lecteur l;

 printf("**********************\n");
 printf("*    BIBLIOTHEQUE    *\n");
 printf("**********************\n\n");

 while (choix != 8) {

   printf("1) Saisir un ouvrage\n");
   printf("2) Saisir un lecteur\n");
   printf("8) Quitter \n");

   printf("\nVotre choix >");
   scanf("%d", &choix);

   switch(choix) {
	 case 1:
		
		 o = saisirOuvrage();
		 afficherOuvrage(o);
		   
	 break;

 	 case 2:
		   
		 l = saisirLecteur();
 		 afficheLecteur(l);

 	 break;

 	 case 8:

 		 printf("Sortie du programme \n");
		 sauvegarde(tabO, tabL, *nbO, *nbL);
		  
 		 return;

	 break;

 	 default:

 		 printf("Merci de rentrer un choix correct \n");

 	 break;
    }
  }
}

int main(void) {
 Ouvrage** tabO = NULL;
 Lecteur** tabL = NULL;
 int nbO = 0, nbL = 0;

 menu(tabO, tabL, &nbO, &nbL);

 return 0;
}

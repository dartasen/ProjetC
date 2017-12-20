#include "lib/lib.h"

void menu(void) {
 int choix = 0;

 printf("**********************\n");
 printf("*    BIBLIOTHEQUE    *\n");
 printf("**********************\n\n");

 while (choix != 8) {

   printf("1) Saisir un ouvrage\n");
   printf("2) ???\n");
   printf("8) Quitter \n");

   printf("\nVotre choix >");
   scanf("%d", &choix);

   switch(choix) {
	 case 1:
		
		   afficherOuvrage(saisirOuvrage());
		   
	 break;

 	 case 2:

 	 break;

 	 case 8:

 		 printf("Sortie du programme \n");
 		 return;

	 break;

 	 default:

 		 printf("Merci de rentrer un choix correct \n");

 	 break;
    }
  }
}

int main(void) {
 menu();

 return 0;
}

#include "liste.h"

void menu(void) {
 int choix = 0;

 printf("**********************\n");
 printf("*    BIBLIOTHEQUE    *\n");
 printf("**********************\n\n");

 while (choix != 8) {

   printf("1) ???\n");
   printf("2) ???\n");
   printf("8) Quitter \n");

   printf("Votre choix >");
   scanf("%d", &choix);

   //Si le choix est de quitter, on arrête
   if (choix == 8)
	   return;

  //Si le choix est incorrect, on relance la boucle
   if (choix < 1 || choix > 2) {
      printf("Le choix est incorrect :( \n");
      continue;
   }
 }

 switch(choix) {

 	 case 1:

	 break;

 	 case 2:

	 break;
 }
}


int main(void) {
 menu();

 return 0;
}

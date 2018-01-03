#include "lib/lib.h"

void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL) {
 int choix = 0, i;
 Ouvrage o;
 Lecteur l;
 char c;

 printf("**********************\n");
 printf("*    BIBLIOTHEQUE    *\n");
 printf("**********************\n\n");

 while (choix != 8) {

   printf("1) Saisir un ouvrage\n");
   printf("2) Saisir un lecteur\n");
   printf("3) Affiche les ouvrages\n");
   printf("8) Quitter \n");

   printf("\nVotre choix > ");
   scanf("%d", &choix);

   switch(choix) {
	 case 1:
		
		 o = saisirOuvrage();
		 afficherOuvrage(o);
		   
		 printf("\nAjouter l'ouvrage ? (o/n)\n");
		 scanf("%c%*c", &c);

		 if (c == 'o')
			 tabO = ajouterOuvrage(tabO, nbO, o);
		   
	 break;

 	 case 2:
	 
 		 l = saisirLecteur();
 		 afficheLecteur(l);

 	 break;

 	 case 3:

 		 printf("\nAffichage de %d Ouvrages \n\n", *nbO);

 		 for (i = 0; i < *nbO; i++)
 			afficherOuvrage(*tabO[i]);

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

 FILE* flotOuvrage = fopen("ouvrage.don", "r");	

 if (flotOuvrage == NULL) {
	 printf("Erreur de fopen de ouvrage.don \n");
	 exit(1);
 }

 tabO = chargeFouvrage(flotOuvrage, &nbO);

 menu(tabO, tabL, &nbO, &nbL);

 fclose(flotOuvrage);

 return 0;
}

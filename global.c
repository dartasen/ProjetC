#include "lib/lib.h"

void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL) {
 int choix = 0;
 Lecteur l;
 char c;

 while (choix != 8) {

   printf("**********************\n");
   printf("*    BIBLIOTHEQUE    *\n");
   printf("**********************\n\n");

   printf("1) Gestion des ouvrages\n");
   printf("2) Saisir un lecteur\n");
   printf("8) Quitter \n");

   printf("\nVotre choix > ");
   scanf("%d", &choix);

   switch(choix) {
	 case 1:
		
		 tabO = SousMenuOuvrage(tabO, nbO);
		 system("cls");

	 break;

 	 case 2:
	 
 		 l = saisirLecteur();
 		 afficheLecteur(l);

		 printf("\nAjouter le lecteur ? (o/n)\n");
		 scanf("%c%*c", &c);

		 if (c == 'o')
			 c += 1;

		 system("cls");

 	 break;

 	 case 8:

 		 sauvegarde(tabO, tabL, *nbO, *nbL);

	 break;

 	 default:

 		 printf("Merci de rentrer un choix correct \n");

 	 break;
    }
  }
}

Ouvrage** SousMenuOuvrage(Ouvrage* tabO[], int* nbO) {
	int choix = 0, i;
	Ouvrage o;
	char c, cote[21];

	while (choix != 8) {
		system("cls");

		printf("**********************\n");
		printf("*      OUVRAGES      *\n");
		printf("**********************\n\n");

		printf("1) Saisir un ouvrage\n");
		printf("2) Supprimer un ouvrage\n");
		printf("3) Afficher les ouvrages\n");
		printf("8) Retourner au menu \n");

		printf("\nVotre choix > ");
		scanf("%d", &choix);

		switch (choix) {

			case 1:

				 o = saisirOuvrage();
				 afficherOuvrage(o);

				 printf("Ajouter l'ouvrage ? (o/n)\n");
				 scanf("%c%*c", &c);

				 if (c == 'o')
					 tabO = ajouterOuvrage(tabO, nbO, o);

			break;

			case 2:

				printf("Saisir la cÃ´te de l'ouvrage Ã  supprimer \n");
				scanf("%s%*c", cote);

				i = rechercherOuvrage(cote, tabO, *nbO);

				printf("\n");

				if (i == -1) {
					printf("Impossible de supprimer cette ouvrage car il n'existe pas !\n");
					break;
				}

				afficherOuvrage(*tabO[i]);
				printf("Supprimer l'ouvrage ? (o/n)\n");
				scanf("%c%*c", &c);

				if (c == 'o')
					tabO = supprimerOuvrage(tabO, nbO, i);

			break;

			case 3:

				 printf("\nAffichage de %d Ouvrages \n\n", *nbO);

				 for (i = 0; i < *nbO; i++)
					afficherOuvrage(*tabO[i]);

			break;

			case 8:
				 return tabO;
			break;

			default:

				 printf("Merci de rentrer un choix correct \n");

			break;
		}

		system("pause");
	}

	return tabO;
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

 system("pause");

 return 0;
}

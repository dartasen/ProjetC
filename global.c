#include "lib/lib.h"

void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL) {
 int choix = 0;

 while (choix != 8) {

   printf("**********************\n");
   printf("*    BIBLIOTHEQUE    *\n");
   printf("**********************\n\n");

   printf("1) Gestion des ouvrages\n");
   printf("2) Gestion des lecteurs\n");
   printf("8) Quitter \n");

   printf("\nVotre choix > ");
   scanf("%d%*c", &choix);

   switch(choix) {
	 case 1:
		
		 tabO = SousMenuOuvrage(tabO, nbO);
		 system("clear");

	 break;

 	 case 2:
	 
 		 tabL = SousMenuLecteur(tabL, nbL);
 		 system("clear");

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

Lecteur** SousMenuLecteur(Lecteur* tabL[], int* nbL) {
	int choix = 0, i, num;
	Lecteur l;
	char c;

	while (choix != 8) {
			system("clear");

			printf("**********************\n");
			printf("*      LECTEURS      *\n");
			printf("**********************\n\n");

			printf("1) Saisir un lecteur\n");
			printf("2) Supprimer un lecteur\n");
			printf("3) Afficher les lecteurs \n");
			printf("8) Retourner au menu \n");

			printf("\nVotre choix > ");
			scanf("%d%*c", &choix);

			switch (choix) {

				case 1:

					l = saisirLecteur();

					printf("\n");

					afficheLecteur(l);

					printf("Ajouter le lecteur ? (o/n)\n");
					scanf("%c%*c", &c);

					if (c == 'o') {
						tabL = ajouterLecteur(tabL, nbL, l);
						trierEchange(tabL, *nbL);
					}

				break;
				
				case 2:

					printf("\nSaisir le numéro du lecteur à supprimer \n");
					scanf("%d%*c", &num);

					i =  rechercheLecteur(num, tabL, *nbL);

					printf("\n");

					if (i == -1) {
						printf("Impossible de supprimer ce lecteur car il n'existe pas !\n");
						break;
					}

					afficheLecteur(*tabL[i]);
					printf("Supprimer le lecteur ? (o/n)\n");
					scanf("%c%*c", &c);

					if (c == 'o')
						tabL = supprimerLecteur(tabL, nbL, i);

				break;

				case 3:

		 			printf("\nAffichage de %d Lecteurs \n\n", *nbL);

				 	for (i = 0; i < *nbL; i++)
						afficheLecteur(*tabL[i]);
						
				break;

				case 8:

				 return tabL;

				break;

			 	default:

			 		 printf("Merci de rentrer un choix correct \n");

			 	break;
			}
			printf("Appuyez sur une touche pour continuer\n");
		 	system("read osef");
	}
	return tabL;
}

Ouvrage** SousMenuOuvrage(Ouvrage* tabO[], int* nbO) {
	int choix = 0, i, choix2 = 0;
	MotClef m = NULL;
	char c, cote[21];
	Ouvrage o;

	while (choix != 8) {
		system("clear");

		printf("**********************\n");
		printf("*      OUVRAGES      *\n");
		printf("**********************\n\n");

		printf("1) Saisir un ouvrage\n");
		printf("2) Supprimer un ouvrage\n");
		printf("3) Modifier un ouvrage\n");
		printf("4) Afficher les ouvrages\n");
		printf("8) Retourner au menu \n");

		printf("\nVotre choix > ");
		scanf("%d%*c", &choix);

		switch (choix) {

			case 1:

				 o = saisirOuvrage();
				 afficherOuvrage(o);

				 printf("Ajouter l'ouvrage ? (o/n)\n");
				 scanf("%c%*c", &c);

				 if (c == 'o')
					 tabO = ajouterOuvrage(tabO, nbO, o);
				
				continue;
			break;

			case 2:

				printf("\nSaisir la côte de l'ouvrage à supprimer \n");
				scanf("%s%*c", cote);

				i = rechercherOuvrage(cote, tabO, *nbO);

				printf("\n");

				if (i == -1) {
					printf("Impossible de supprimer cet ouvrage car il n'existe pas !\n");
					break;
				}

				afficherOuvrage(*tabO[i]);
				printf("Supprimer l'ouvrage ? (o/n)\n");
				scanf("%c%*c", &c);

				if (c == 'o')
					tabO = supprimerOuvrage(tabO, nbO, i);

			break;

			case 3:

				printf("\nSaisir la cote de l'ouvrage à modifier \n");
				scanf("%s%*c", cote);

				i = rechercherOuvrage(cote, tabO, *nbO);

				if (i == -1) {
					printf("\nImpossible de modifier cet ouvrage car il n'existe pas !\n");
					break;
				}
				
				Ouvrage o = *tabO[i];
				choix2 = 0;

				while (choix2 != 8) {
					printf("\n1) Modifier le titre | 2) Modifier la catégorie | 3) Modifier la quantité | 4) Modifier les mots clefs | 8) Quitter \n\nVotre choix > ");
					scanf("%d%*c", &choix2);

					switch (choix2) {
						case 1:
								printf("\n> Titre actuel : %s\n> Nouveau titre : ", o.titre);
								fgets(o.titre, sizeof(o.titre), stdin);
								o.titre[strlen(o.titre) - 1] = '\0';

								printf("\nLe titre de l'ouvrage a été modifié !\n");
						break;

						case 2:
								printf("\n> Catégorie actuel : %s\n> Nouvelle catégorie : ", o.categorie);
								fgets(o.categorie, sizeof(o.categorie), stdin);
								o.categorie[strlen(o.categorie) - 1] = '\0';

								printf("\nLa catégorie de l'ouvrage a été modifiée !\n");
						break;

						case 3:
								printf("\nQuantité actuelle : %d\n> Nouvelle quantité : ", o.quantite);
								scanf("%d%*c", &o.quantite);

								while (o.quantite < 0) {
									printf("! Une quantité ne peut-être négative ! \n");
									printf("Saisir la quantité de livre \n");
									scanf("%d%*c", &o.quantite);
								}

								printf("\nLa quantité de l'ouvrage a été modifiée ! \n");
						break;
							
						case 4:
								m = (MaillonMot*) malloc(sizeof(MaillonMot));

								if (m == NULL) {
									printf("Erreur de malloc des MotClefs \n");
									exit(1);
								}
			
								printf("\n> Mots-Clefs actuels :");
							        afficherMotClef(o.motclefs);

								printf("> Nouveau Mots-Clefs (:q pour quitter) \n");
								printf("Saisie > ");
	
								scanf("%s%*c", cote);
								strcpy(m->mot, cote);
								m->suiv = NULL;

								while (strcmp(cote, ":q") != 0) {
									printf("Saisie > ");
									scanf("%s%*c", cote);
									insererMotClef(m, cote);
								}

								if (longueurMotClef(m) == 1 && strcmp(cote,":q") != 0)
									strcpy(m->mot, "AUCUN");
								
								supprimerMC(o.motclefs);
								o.motclefs = m;

						break;

						case 8:

								printf("\n");
								afficherOuvrage(o);

								printf("Modifier l'ouvrage ? (o/n)\n");
								scanf("%c%*c", &c);

								if (c == 'o')
									*tabO[i] = o;

						break;

						default:

								printf("\nMerci de rentrer un choix correct \n");
								choix = 0;

						break;
					}
				}

			break;

			case 4:

				 printf("\nAffichage de %d Ouvrages \n\n", *nbO);

				 for (i = 0; i < *nbO; i++)
					afficherOuvrage(*tabO[i]);

			break;

			case 8:
				 return tabO;
			break;

			default:

				 printf("\nMerci de rentrer un choix correct \n");

			break;
		}

 		 printf("Appuyez sur une touche pour continuer\n");
		 system("read osef");
	}

	return tabO;
}

int main(void) {
 Ouvrage** tabO = NULL;
 Lecteur** tabL = NULL;
 int nbO = 0, nbL = 0;

 system("osef=0");

 FILE* flotOuvrage = fopen("ouvrage.don", "r");
 FILE* flotLecteur = fopen("lecteur.don", "rb");

 if (flotOuvrage == NULL || flotLecteur == NULL) {
	 printf("Erreur de fopen de ouvrage.don \n");
	 exit(1);
 }

 tabO = chargeFouvrage(flotOuvrage, &nbO);
 tabL = chargementBinLecteur(flotLecteur, &nbL);

 menu(tabO, tabL, &nbO, &nbL);

 fclose(flotOuvrage);

 printf("Appuyez sur une touche pour continuer\n");
 system("read osef");

 return 0;
}

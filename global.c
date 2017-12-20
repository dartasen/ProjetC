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

ListeEmprunt nouvelEmprunt(Lecteur l, Ouvrage o)
{
	if (o.quantite - o.quantiteEmprunt <=0)
		{
			printf("Impossible d'emprunter l'ouvrage \n");
			return l.emprunt;
		}
	if (longueurListeEmprunt(l.emprunt) ==5)
		{
			printf("Vous avez déjà emprunter 5 livres \n");
			return l.emprunt;
		}
	l.emprunt=insererEnTeteEmprunt(l.emprunt,o);
}
void sauvegardeBin (Ouvrage **tabOuvrage , Lecteur **tabLecteur, int nbOuvrage , int nbLecteur)
{
	fopen("sauv.bin","wb");
	f.write()
}
int main(void) {
 menu();

 return 0;
}

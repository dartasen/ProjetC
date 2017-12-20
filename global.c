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

Ouvrage saisirOuvrage(void) {
	MotClef m = MotVide();
	char c[20];
	Ouvrage o;

	printf("\nSaisir la côte de l'ouvrage \n");
	scanf("%s%*c", o.cote);

	printf("Saisir le titre du livre \n");
	fgets(o.titre, sizeof(o.titre), stdin);
	o.titre[strlen(o.titre) - 1] = '\0';

	printf("Saisir le nom de la catégorie \n");
	fgets(o.categorie, sizeof(o.categorie), stdin);
	o.categorie[strlen(o.categorie) - 1] = '\0';

	printf("Saisir la quantité de livre \n");
	scanf("%d", &o.quantite);

	m = (MotClef) malloc(sizeof(MaillonMot));

	if (m == NULL) {
		printf("Erreur de malloc des MotClefs \n");
		exit(1);
	}

	printf("Saisir les mot-clefs non composés du livre (:q pour quitter) \n");

	while (strcmp(c, ":q") != 0) {
		printf("Saisie > ");
		scanf("%s", c);
		insererMotClef(m, c);
	}

	o.quantiteEmprunt = 0;
	o.motclefs = m;

	return o;
}

void afficherOuvrage(Ouvrage o) {
	printf("%s \n", o.titre);
	printf("> Côte : %s \n", o.cote);
	printf("> Catégorie : %s \n", o.categorie);
	printf("> Quantité : %d (- %d) \n", o.quantite, o.quantiteEmprunt);
	afficherMotClef(o.motclefs);

	printf("\n");
}

ListeEmprunt  insererEnTeteEmprunt(ListeEmprunt l, Ouvrage o)
{
	MaillonEmprunt *m;
	m= (MaillonEmprunt *)malloc(sizeof(MaillonEmprunt));
	if (m==NULL)
	{
		printf("erreur malloc \n");
		exit(1);
	}
	strcpy(m->emp.cote, o.cote);
	m->suiv = l;
	return m;
}

int longueurListeEmprunt(ListeEmprunt e)
{
	if (e->suiv == NULL)
		return 0;
	return 1+longueurListeEmprunt(e->suiv);
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

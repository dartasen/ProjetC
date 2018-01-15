#include "lib/lib.h"


//ancienne version
/*
void nouvelEmprunt(Lecteur l, Ouvrage o) {
	
	if (o.quantite - o.quantiteEmprunt <= 0)
		printf("Impossible d'emprunter l'ouvrage \n");
	else if (longueurEmprunt(l.emprunt) == 5)
		printf("Vous avez déjà  emprunter 5 livres \n");

	l.emprunt = insererEmprunt(l.emprunt, o.cote);
	o.quantiteEmprunt += 1;
	o.quantite -= 1;
}
*/ 
void nouvelEmprunt(int numeroLecteur, Lecteur **tabl, int nbL, char cote[],Ouvrage **tabO, int nbo)
{
    int poso,posl;
    poso = rechercheDichoOuvrage(cote, tabO, nbo);
    posl = rechercheDichoLecteur(numeroLecteur, tabl, nbL);
    if (poso == -1 || posl == -1)
    {
        printf("Le Lecteur ou l'ouvrage n'existe pas \n");
        return;
    }
	if (tabO[poso]->quantite - tabO[poso]->quantiteEmprunt == 0)
		{
            printf("Impossible d'emprunter l'ouvrage \n");
            return;
        }
	else if (tabl[posl]->nbEmprunt >=5)
    {
		printf("Vous avez déjà  emprunter 5 livres \n");
        return;
    }

	tabl[posl]->emprunt = insererEmprunt(tabl[posl]->emprunt, tabO[poso]->cote);
	tabO[poso]->quantiteEmprunt += 1;
    tabl[posl]->nbEmprunt+=1;
}

void retourEmprunt(int numeroLecteur, Lecteur **tabl, int nbL, char cote[],Ouvrage **tabO, int nbo)
{
    int poso,posl;
    poso = rechercheDichoOuvrage(cote, tabO, nbo);
    posl = rechercheDichoLecteur(numeroLecteur, tabl, nbL);
    if (poso == -1 || posl == -1)
    {
        printf("Le Lecteur ou l'ouvrage n'existe pas \n");
        return;
    }
    tabl[posl]->emprunt=supprimerEmprunt(tabl[posl]->emprunt,tabO[poso]->cote);
    tabO[poso]->quantiteEmprunt -=1;
    tabl[posl]->nbEmprunt -=1;
}




Emprunt EmpruntVide(void) {
	return NULL;
}

Emprunt insererEnTeteEmpruntBin(Emprunt m, char cote[], Date date) {
	Emprunt aux = (Emprunt) malloc(sizeof(MaillonEmprunt));
	
	if (aux == NULL) {
		printf("Erreur malloc emprunt \n");
		exit(1);
	}
	
	strcpy(aux->cote,cote);
	aux->date = date;
	aux->suiv=m;
	
	return aux;
}

Emprunt insererEnTeteEmprunt(Emprunt m, char cote[]) {
	Emprunt aux = (Emprunt) malloc(sizeof(MaillonEmprunt));
	time_t secondes;
	struct tm maintenant;
	time(&secondes);
	maintenant = *localtime(&secondes);

	if (aux == NULL) {
	    printf("Erreur de malloc de Emprunt \n");
	    exit(1);
	}

	strcpy(aux->cote, cote);
	aux->date.j = maintenant.tm_mday;
	aux->date.m = maintenant.tm_mon +1;
	aux->date.a = maintenant.tm_year + 1900;
	aux->suiv = m;

	return aux;
}

Emprunt insererEmprunt(Emprunt m, char cote[]) {
	if (m == EmpruntVide())
		return insererEnTeteEmprunt(m, cote);

	if (strcmp(m->cote, cote) > 0)
		return insererEnTeteEmprunt(m, cote);

	if (strcmp(m->cote, cote) == 0)
		return m;

	m->suiv = insererEmprunt(m->suiv, cote);

	return m;
}

Emprunt supprimerEnTeteEmprunt(Emprunt m) {
	MaillonEmprunt* temp;

	if (m == NULL) {
		printf("Erreur lors de la suppression en tÃªte \n");
		exit(1);
	}

	temp = m;
	m = m->suiv;
	free(temp);

	return m;
}

Emprunt supprimerEmprunt(Emprunt m, char cote[]) {
	if (m == NULL)
		return m;

	if (strcmp(m->cote, cote) > 0)
		return m;

	if (strcmp(m->cote, cote) == 0)
		return supprimerEnTeteEmprunt(m);

	m->suiv = supprimerEmprunt(m->suiv, cote);

	return m;
}

int longueurEmprunt(Emprunt m) {
	if (m == NULL)
		return 0;

	return 1 + longueurEmprunt(m->suiv);
}

void afficherEmprunt(Emprunt m) {
	if (m == NULL) {
		printf("\n");
		return;
	}

	printf("%s -> %d/%d/%d \n", m->cote, m->date.j, m->date.m, m->date.a);
	afficherEmprunt(m->suiv);
}

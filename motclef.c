#include "lib/lib.h"

MotClef MotVide(void) {
	return NULL;
}

MotClef insererEnTeteMotClef(MotClef m, char mot[]) {
	MotClef aux = (MotClef) malloc(sizeof(MaillonMot));

	if (aux == NULL) {
	    printf("Erreur de malloc de motClef \n");
	    exit(1);
	}

	strcpy(aux->mot, mot);
	aux->suiv = m;

	return aux;
}

MotClef insererMotClef(MotClef m, char mot[]) {
	if (m == MotVide())
		return insererEnTeteMotClef(m, mot);

	if (strcmp(m->mot, mot) > 0)
		return insererEnTeteMotClef(m, mot);

	if (strcmp(m->mot, mot) == 0)
		return m;

	m->suiv = insererMotClef(m->suiv, mot);

	return m;
}

MotClef supprimerEnTeteMotClef(MotClef m) {
	MaillonMot* temp;

	if (m == NULL) {
		printf("Erreur lors de la suppression en tête \n");
		exit(1);
	}

	temp = m;
	m = m->suiv;
	free(temp);

	return m;
}

MotClef supprimerMotClef(MotClef m, char mot[]) {
	if (m == NULL)
		return m;

	if (strcmp(m->mot, mot) > 0)
		return m;

	if (strcmp(m->mot, mot) == 0)
		return supprimerEnTeteMotClef(m);

	m->suiv = supprimerMotClef(m->suiv, mot);

	return m;
}

int longueurMotClef(MotClef m) {
	if (m == NULL)
		return 0;

	return 1 + longueurMotClef(m->suiv);
}

void afficherMotClef(MotClef m) {
	if (m == NULL) {
		printf("\n");
		return;
	}
	
	if (m->suiv == NULL) {
		printf("%s\n", m->mot);
		return;
	}
	
	printf("%s, ", m->mot);
	afficherMotClef(m->suiv);
}

void ecrireMotClef(FILE* fichier, MotClef m) {
	if (m == NULL) {
		printf("\n");
		return;
	}

	fprintf(fichier, "%s:", m->mot);
}

char** explit(char delimiteur, char* mot, int* taille) {
	int longueur = strlen(mot), i = 0, j = 0, k = 0;
	char x, **tabmot;

	tabmot = (char**) malloc(sizeof(char**));
	tabmot[0] = (char*) malloc(longueur * sizeof(char));

	if (tabmot == NULL) {
		printf("Erreur de malloc pour le explode \n");
		exit(1);
	}

	while (i <= longueur) {
		x = mot[i++];

		if (x == delimiteur || x == '\0') {
			tabmot[j][k] = '\0';
			tabmot[j] = (char*) realloc(tabmot[j], k * sizeof(char));

			k = 0;
			// ++j+1 = (j += 1) + 1 = (j = j + 1) + 1

			tabmot = (char**) realloc(tabmot, (++j+1) * sizeof(char**));
			tabmot[j] = (char*) malloc(longueur * sizeof(char));
		} else
			tabmot[j][k++] = x;
	}

	*taille = j;

	return tabmot;
}

MotClef lireMotClef(char* serial) {
	MotClef lmot = MotVide();
	char **motsplit = NULL;
	int i, taille = 0;

	motsplit = explode(':', serial, &taille);

	for (i = 0; i < taille; i++)
		lmot = insererEnTeteMotClef(lmot, motsplit[i]);

	return lmot;
}

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

	printf("%s", m->mot);
	afficherMotClef(m->suiv);
}

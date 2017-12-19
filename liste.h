MotClef MotVide(void) {
	return NULL;
}

MotClef insererEnTete(MotClef m, char mot[]) {
	MotClef sauv = m;
	m = (MotClef) malloc(sizeof(maillonMot));

	if (m == NULL) {
		printf("Erreur de malloc de motClef \n");
	    exit(1);
	}

	strcpy(m->mot, mot);
	m->suiv = m;

	return m;
}

MotClef inserer(MotClef m, char mot[]) {
	if (m == MotVide())
		return insererEnTete(m, mot);
	
	if (strcmp())
}

int compter(MotClef m) {
	if (m == NULL)
		return 0;

	return 1 + compter(m->suiv);
}

int main(void) {

	return 0;
}

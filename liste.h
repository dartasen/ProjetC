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

	if (strcmp(m->mot, mot) < 0)
		return insererEnTete(m, mot);

	if (strcmp(m->mot, mot) == 0)
		return m;

	m->suiv = inserer(m->suiv, m);

	return m;
}

MotClef supprimerEnTete(MotClef m) {
	maillonMot* temp;

	if (m == NULL) {
		printf("Erreur lors de la suppression en tête \n");
		exit(1);
	}

	temp = m;
	m = m->suiv;
	free(temp);

	return m;
}

MotClef supprimer(MotClef m, char mot[]) {
	if (m == NULL)
		return m;

	if (strcmp(m->mot, mot) < 0)
		return m;

	if (strcmp(m->mot, mot) == 0)
		return supprimerEnTete(m);

	m->suiv = supprimer(m->suiv, mot);

	return m;
}

int longueur(MotClef m) {
	if (m == NULL)
		return 0;

	return 1 + longueur(m->suiv);
}

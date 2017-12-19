/* Fonction pour compter les mots clefs */

int compter(MotClef m) {
	if (m == NULL)
		return 0;

	return 1 + compter(m->suiv);
}

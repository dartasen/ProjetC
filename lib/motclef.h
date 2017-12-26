void afficherMotClef(MotClef m);
int longueurMotClef(MotClef m);
MotClef supprimerMotClef(MotClef m, char mot[]);
MotClef supprimerEnTeteMotClef(MotClef m);
MotClef insererMotClef(MotClef m, char mot[]);
MotClef insererEnTeteMotClef(MotClef m, char mot[]);
MotClef MotVideMotClef(void);
MotClef lireMotClef(FILE* fichier);
void ecrireMotClef(FILE* fichier, MotClef m);
char** explit(char delimiteur, char* mot, int* taille);

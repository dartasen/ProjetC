//On insère ici les prototypes des fonctions

void menu(void);

Ouvrage saisirOuvrage(void);
void afficherOuvrage(Ouvrage o);

void afficherMotClef(MotClef m);
int longueurMotClef(MotClef m);
MotClef supprimerMotClef(MotClef m, char mot[]);
MotClef supprimerEnTeteMotClef(MotClef m);
MotClef insererMotClef(MotClef m, char mot[]);
MotClef insererEnTeteMotClef(MotClef m, char mot[]);
MotClef MotVideMotClef(void);

Emprunt nouvelEmprunt(Lecteur l, Ouvrage o);

void trierEchange(Lecteur* tab[], int nb);
int rechercheEchange(Lecteur* tab[], int nb);
void echangerEchange(Lecteur* tab[], int i, int j);
int comparerNomPrenom(char* nom, char* prenom, char* nom1, char* prenom);

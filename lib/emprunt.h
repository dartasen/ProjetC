void nouvelEmprunt(Lecteur l, Ouvrage o);
Emprunt EmpruntVide(void);
Emprunt insererEnTeteEmprunt(Emprunt m, char cote[]);
Emprunt insererEmprunt(Emprunt m, char cote[]);
Emprunt insererEnTeteEmpruntBin(Emprunt m, char cote[], Date date);
Emprunt supprimerEnTeteEmprunt(Emprunt m);
Emprunt supprimerEmprunt(Emprunt m, char cote[]);
int longueurEmprunt(Emprunt m);
void afficherEmprunt(Emprunt m);

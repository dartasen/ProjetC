void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL);
void sauvegarde(Ouvrage* tabO[], Lecteur* tabL[], int nbO, int nbL);
int sauvegardeLecteur(Lecteur* tab[], int nbr);
int sauvegardeOuvrage(Ouvrage* tab[], int nbr);
Ouvrage** chargeFouvrage(FILE* fichier, int* nbO);
Ouvrage** ajouterOuvrage(Ouvrage** tab, int* nbO, Ouvrage o);

// ???????????????????????????????????????
void sauvegardeBin(Ouvrage **tabO, Lecteur ** tabL, int nbO, int nbL);
int sauvegardeBinMotClef(Ouvrage ouv);
int sauvegardeBinEmprunt(Lecteur l);
// ???????????????????????????????????????

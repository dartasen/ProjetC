void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL);
void sauvegarde(Ouvrage* tabO[], Lecteur* tabL[], int nbO, int nbL);
int sauvegardeLecteur(Lecteur* tab[], int nbr);
int sauvegardeOuvrage(Ouvrage* tab[], int nbr);
Ouvrage** chargeFouvrage(FILE* fichier, int* nbO);
Ouvrage** ajouterOuvrage(Ouvrage** tab, int* nbO, Ouvrage o);
void streplace(char mot[], char remplacer, char remplacant);

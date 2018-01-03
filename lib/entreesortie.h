void menu(Ouvrage* tabO[], Lecteur* tabL[], int* nbO, int* nbL);
Ouvrage** SousMenuOuvrage(Ouvrage* tabO[], int* nbO);
void sauvegarde(Ouvrage* tabO[], Lecteur* tabL[], int nbO, int nbL);
int sauvegardeLecteur(Lecteur* tab[], int nbr);
int sauvegardeOuvrage(Ouvrage* tab[], int nbr);
Ouvrage** chargeFouvrage(FILE* fichier, int* nbO);
void streplace(char mot[], char remplacer, char remplacant);

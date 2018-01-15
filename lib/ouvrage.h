Ouvrage saisirOuvrage(void);
void afficherOuvrage(Ouvrage o);
Ouvrage lireOuvrage(FILE* fichier);
int rechercherOuvrage(char cote[], Ouvrage* tabO[], int nbO);
Ouvrage** ajouterOuvrage(Ouvrage** tab, int* nbO, Ouvrage o);
Ouvrage** supprimerOuvrage(Ouvrage* tabO[], int* nbO, int i);
int rechercheDichoOuvrage(char cote[], Ouvrage **o, int nb);

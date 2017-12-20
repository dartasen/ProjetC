ListeEmprunt nouvelEmprunt(Lecteur l, Ouvrage o)
{
	if (o.quantite - o.quantiteEmprunt <=0)
		{
			printf("Impossible d'emprunter l'ouvrage \n");
			return l.emprunt;
		}
	if (longueurListeEmprunt(l.emprunt) ==5)
		{
			printf("Vous avez déjà emprunter 5 livres \n");
			return l.emprunt;
		}
	l.emprunt=insererEnTeteEmprunt(l.emprunt,o);
}

void sauvegardeBin (Ouvrage **tabOuvrage , Lecteur **tabLecteur, int nbOuvrage , int nbLecteur)
{
	fopen("sauv.bin","wb");
	f.write()
}

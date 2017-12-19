#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct {
	int j, m , a;
} Date;

typedef struct {
	char cote[21];
	Date date;
} Emprunt;

typedef struct maillonEmprunt {
	Emprunt emp;
	struct maillonEmprunt* suiv;
} *Liste, MaillonEmprunt;

typedef struct maillonMot {
	char mot[21];
	struct maillonMot* suiv;
} *MotClef, maillonMot;

typedef struct {
	int numLecteur;
	char nom[31];
	char prenom[31];
	Liste emprunt;
} Lecteur;

typedef struct {
	char cote[21];
	char titre[31];
	char categorie[16];
	int quantite;
	int quantiteEnmprunt;
	MotClef motclefs;
} Ouvrage;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int j, m , a;
} Date;

typedef struct maillonEmprunt {
	char cote[21];
	Date date;
	struct maillonEmprunt* suiv;
} *Emprunt, MaillonEmprunt;

typedef struct maillonMot {
	char mot[21];
	struct maillonMot* suiv;
} *MotClef, MaillonMot;

typedef struct {
	int numLecteur;
	char nom[31];
	char prenom[31];
	int nbEmprunt;
	Emprunt emprunt;
} Lecteur;

typedef struct {
	char cote[21];
	char titre[31];
	char categorie[16];
	int quantite;
	int quantiteEmprunt;
	MotClef motclefs;
} Ouvrage;

#include "motclef.h"
#include "ouvrage.h"
#include "lecteur.h"
#include "entreesortie.h"
#include "emprunt.h"

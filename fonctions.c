#include "Liste.h"




Liste ajouterEnTete(Liste l,int x)
{
 Maillon *m;
 m = (Maillon*)malloc(sizeof(Maillon));
 if(m == NULL)
 {
   printf("Pb lors d'ajouterEnTete\n");
   exit(1);
 }
 m->v = x;
 m->suiv = l;
 return m;
 }

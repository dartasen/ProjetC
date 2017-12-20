Lecteur saisirLecteur(void) {
  
  Lecteur l;
  printf("Saisissez le nom du lecteur");
  scanf("%d", &l.nom);
  
  printf("Saisissez le prénom du lecteur");
  scanf("%d*c", &l.prenom);
        
  printf("Saisissez le numéro du lecteur");
  scanf("%s", l.numLecteur);
        
  l.Emprunt = NULL;
}

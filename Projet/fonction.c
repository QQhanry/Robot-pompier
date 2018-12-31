#include "fonction.h"

map  LectureFichier(char *fichier){
  FILE* Appart = NULL;
  map Lecture;

  int i;
  int j;

  Appart = fopen(fichier,"r"); //ouverture map

  if (Appart != NULL) {
    printf("Le fichier est en lecture\n" ); //le fichier est ouvert et peut être lu
  }else{
    printf("Le fichier ne peut être ouvert\n" );
  }

  fscanf(Appart,"%d:%d",&(Lecture.longueur),&(Lecture.largeur));
  printf("longueur:%d largeur:%d\n",Lecture.longueur,Lecture.largeur );


  for ( i = 1; i < Lecture.largeur+1; i++) {
    for (j = 0; j < Lecture.longueur+1; j++) { // mise en place carte
      fscanf(Appart,"%c",&(Lecture.tab[i][j]));

    }

  }
  printf("\n" );
  return Lecture; // la fonction renvoie une variable de type map
}

map AffichageFichier(map Lecture){ //fonction qui prend en parametre une variable de type map
  int i, j;

  for ( i = 1; i < Lecture.largeur+1; i++) {
    for (j = 0; j < Lecture.longueur+1; j++) {
      if (Lecture.tab[i][j]== DEPART) {
        Lecture.position_ent_x=i;   //lecture place du depart
        Lecture.position_ent_y=j;
      }
      if (Lecture.tab[i][j]=='E') { //lecture place extincteur
        Lecture.position_ext_x=i;
        Lecture.position_ext_y=j;

      }
      printf("%c",Lecture.tab[i][j] );

    }

  }
  printf("\n" );

  printf("\n" );
  return Lecture; // return une variable de type map
}

map InitRobot(map Lecture){ // fonction qui prend en parametre une variable de type map
  Wall_E LeRobot;
  //intialisation depart
  LeRobot.position_rob_x=Lecture.position_ent_x;
  LeRobot.position_rob_y=Lecture.position_ent_y;

  if (LeRobot.position_rob_x==Lecture.position_ent_x && LeRobot.position_rob_y==Lecture.position_ent_y) {
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
  }
  AffichageFichier( Lecture);

  Lecture.tab[Lecture.position_ent_x][Lecture.position_ent_y]=DEPART;
  //initialisation en fonction de l'endroit de depart
  if (Lecture.tab[Lecture.position_ent_x][Lecture.position_ent_y-1] == WALL && Lecture.position_ent_x ==0  ) {
    (LeRobot.position_rob_x)++;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
  }else if(Lecture.tab[Lecture.position_ent_x ][Lecture.position_ent_y+1] == WALL && Lecture.position_ent_x >0 && Lecture.position_ent_x <=Lecture.largeur){
    (LeRobot.position_rob_x)--;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
  }else if(Lecture.tab[Lecture.position_ent_x -1][Lecture.position_ent_y] == WALL && Lecture.position_ent_y>=0 && Lecture.position_ent_y <Lecture.longueur){
    (LeRobot.position_rob_y)++;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
  }else if(Lecture.tab[Lecture.position_ent_x +1][Lecture.position_ent_y] == WALL && Lecture.position_ent_y <=Lecture.longueur && Lecture.position_ent_y >0){
    (LeRobot.position_rob_y)--;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
  }
  usleep(100000);
  AffichageFichier( Lecture);

  return Lecture; // return  une variable de type map
}

map DeplacementBase(map Lecture){
  Wall_E LeRobot;
  int Reponse;



  //trouver extincteur

  // deplacement vers la gauche

    if ( Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y -1]==' ') {
    while ((Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y] ==WALL || Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y] == DEPART) && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!=WALL && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='E' && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='P') {
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      if (Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]==' ' || Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=='R') {
        Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';

      }

      (LeRobot.position_rob_y)--;
      usleep(100000);
      AffichageFichier( Lecture);

    }
    (LeRobot.position_rob_y)++;

    }



    //vers le haut

if ( Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y ]==' ' ) {
  while ((Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1] == WALL ||Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1] == DEPART) && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!=WALL && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='E' && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='P') {

          Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y ]='R';
        if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]==' ' || Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=='R'  ) {
          Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=' ';

        }else if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=='1') {
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]=='1';
        }

        (LeRobot.position_rob_x)--;
        usleep(100000);
        AffichageFichier( Lecture);

      }

      LeRobot.position_rob_x++;



}

  // deplacement vers la droite

if ( Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y  ]==WALL ) {
  while (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y] == WALL && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y] != WALL && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='E' && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='P') {
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
    if ( Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]== ' ' || Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]== 'R') {
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';

    }

    (LeRobot.position_rob_y)++;
    usleep(100000);
    AffichageFichier( Lecture);
  }
  (LeRobot.position_rob_y)--;


}

  // deplacement vers le bas

if ( Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y+1 ]==WALL) {
  while ((Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1] == WALL || Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y+1] == DEPART) && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y] != WALL && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='E' && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='P') {
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
        if (Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]==' ' || Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=='R') {
          Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';

        }

        (LeRobot.position_rob_x)++;

        usleep(100000);
        AffichageFichier( Lecture);


      }
      (LeRobot.position_rob_x)--;

 }

 // Robot devient porteur de l'extincteur en fonction de la position d'arrivée du robot
 if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=='E') {
   Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=' ';
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
   usleep(100000);
   AffichageFichier( Lecture);
 }else if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=='E') {
   Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=' ';
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
   usleep(100000);
   AffichageFichier( Lecture);
 }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]=='E') {
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]=' ';
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
   usleep(100000);
   AffichageFichier( Lecture);
 }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]=='E') {
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]=' ';
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
   usleep(100000);
   AffichageFichier( Lecture);
 }

return Lecture; // return
}

map DeplacementComp(map Lecture){
  Wall_E LeRobot;
  int i;
  if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1 ]==WALL && Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y+1 ]==' ' && Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y ]==' ') {
                                // passage de la verticale en venant de la gauche
    LeRobot.position_rob_x++;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
    Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';

    usleep(100000);
    AffichageFichier( Lecture);
    for ( i = 0; i < 2; i++) {
      LeRobot.position_rob_y++;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';
      usleep(100000);
      AffichageFichier( Lecture);
    }
    if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y ]!=WALL) {
      LeRobot.position_rob_x--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]=' ';
    }

    usleep(100000);
    AffichageFichier( Lecture);

  }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1 ]==WALL && Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y-1 ]==' ' && Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y ]==' ') {
                      // passage de la verticale en venant de la droite
    LeRobot.position_rob_x--;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
    Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]=' ';

    usleep(100000);
    AffichageFichier( Lecture);
    for ( i = 0; i < 2; i++) {
      LeRobot.position_rob_y--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';
      usleep(100000);
      AffichageFichier( Lecture);
    }
    if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]!=WALL) {
      LeRobot.position_rob_x++;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';
    }


    usleep(100000);
    AffichageFichier( Lecture);


  }


//passage de la barre laterale  en venant de la  droite
    if (Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]==WALL && Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]==' ' && Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y+1]==' ') {
      LeRobot.position_rob_y++;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';

      usleep(100000);
      AffichageFichier( Lecture);
      for ( i = 0; i < 2; i++) {
        LeRobot.position_rob_x--;
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
        Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]=' ';
        usleep(100000);
        AffichageFichier( Lecture);
      }
      LeRobot.position_rob_y--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';

      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]==WALL && Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]==' ' && Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y-1]==' ') {
      LeRobot.position_rob_y--;   // passage de la barre laterale en venant de la gauche
      LeRobot.position_rob_y--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';

      usleep(100000);
      AffichageFichier( Lecture);
      for ( i = 0; i < 2; i++) {
        LeRobot.position_rob_x++;
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
        Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';
        usleep(100000);
        AffichageFichier( Lecture);
      }

        LeRobot.position_rob_y++;
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='R';
        Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';



      usleep(100000);
      AffichageFichier( Lecture);
    }

    //Passage du robot non porteur à porteur à l'approche de l'extincteur
    // s'il est à une case de celui-ci il devient porteur
    if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=='E') {
      Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=' ';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=='E') {
      Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=' ';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]=='E') {
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]=' ';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]=='E') {
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]=' ';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      usleep(100000);
      AffichageFichier( Lecture);
    }



  return Lecture;
}

map DeplacementBase2(map Lecture){
  Wall_E LeRobot;
  int Reponse;



  //trouver le feu

  // direction vers la gauche

    if ( Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y -1]==' ') {
    while ((Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y] ==WALL || Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y] == DEPART) && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!=WALL &&  Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='1' ) {
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      if (Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]==' ' || Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=='P') {
        Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';

      }

      (LeRobot.position_rob_y)--;
      usleep(100000);
      AffichageFichier( Lecture);

    }
    (LeRobot.position_rob_y)++;

    }



    //direction vers le haut

if ( Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y ]==' ' ) {
  while ((Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1] == WALL ||Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1] == DEPART) && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!=WALL &&  Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='1') {

          Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y ]='P';
        if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]==' ' || Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=='P') {
          Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=' ';

        }

        (LeRobot.position_rob_x)--;
        usleep(100000);
        AffichageFichier( Lecture);

      }

      LeRobot.position_rob_x++;



}

  // direction vers la droite

if ( Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y  ]==WALL ) {
  while (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y] == WALL && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y] != WALL &&  Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='1' ) {
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
    if ( Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]== ' ' || Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]== 'P') {
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';

    }

    (LeRobot.position_rob_y)++;
    usleep(100000);
    AffichageFichier( Lecture);
  }
  (LeRobot.position_rob_y)--;


}

  //direction vers le bas

if ( Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y+1 ]==WALL) {
  while ((Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1] == WALL || Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y+1] == DEPART) && Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y] != WALL &&  Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='1') {
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
        if (Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]==' ' || Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=='P') {
          Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';

        }

        (LeRobot.position_rob_x)++;

        usleep(100000);
        AffichageFichier( Lecture);


      }
      (LeRobot.position_rob_x)--;

 }

 //Si le robot arrive sur le feu, l'objectif est atteint
 if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=='1') {
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]=Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y];
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';

   usleep(100000);
   AffichageFichier( Lecture);
   printf("Mission accomplie!\n" );/
 }else if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=='1') {
  Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]= Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y];
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';

   usleep(100000);
   AffichageFichier( Lecture);
   printf("Mission accomplie!\n" );
 }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]=='1') {
  Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]= Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1];
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';

   usleep(100000);
   AffichageFichier( Lecture);
   printf("Mission accomplie!\n" );
 }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]=='1') {
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]=Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1];
   Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';

   usleep(100000);
   AffichageFichier( Lecture);
   printf("Mission accomplie!\n" );
 }


return Lecture;
}
map DeplacementComp2(map Lecture){
  Wall_E LeRobot;
  int i;

  //deplacement comme ceux de la fonction DeplacementComp mais lorsque le robot est porteur de l'extincteur
  if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1 ]==WALL && Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y+1 ]==' ' && Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y ]==' ') {
    // passage de la barre verticale en venant de la gauche
    LeRobot.position_rob_x++;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
    Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';

    usleep(100000);
    AffichageFichier( Lecture);
    for ( i = 0; i < 2; i++) {
      LeRobot.position_rob_y++;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';
      usleep(100000);
      AffichageFichier( Lecture);
    }
    if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y ]!=WALL) {
      LeRobot.position_rob_x--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]=' ';
    }

    usleep(100000);
    AffichageFichier( Lecture);

  }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1 ]==WALL && Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y-1 ]==' ' && Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y ]==' ') {
      //passage de la verticale en venant droite
    LeRobot.position_rob_x--;
    Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
    Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]=' ';

    usleep(100000);
    AffichageFichier( Lecture);
    for ( i = 0; i < 2; i++) {
      LeRobot.position_rob_y--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';
      usleep(100000);
      AffichageFichier( Lecture);
    }
    if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]!=WALL) {
      LeRobot.position_rob_x++;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';
    }


    usleep(100000);
    AffichageFichier( Lecture);


  }


//passage de la laterale en venant de la droite
    if (Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]==WALL && Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]==' ' && Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y+1]==' ') {
      LeRobot.position_rob_y++;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';

      usleep(100000);
      AffichageFichier( Lecture);
      for ( i = 0; i < 2; i++) {
        LeRobot.position_rob_x--;
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
        Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]=' ';
        usleep(100000);       // laterale droite
        AffichageFichier( Lecture);
      }
      LeRobot.position_rob_y--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';

      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y]==WALL && Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]==' ' && Lecture.tab[(LeRobot.position_rob_x)+1][LeRobot.position_rob_y-1]==' ') {
      LeRobot.position_rob_y--; // passage de la laterale en venant de la gauche
      LeRobot.position_rob_y--;
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
      Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y+1]=' ';

      usleep(100000);
      AffichageFichier( Lecture);
      for ( i = 0; i < 2; i++) {
        LeRobot.position_rob_x++;
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
        Lecture.tab[(LeRobot.position_rob_x)-1][LeRobot.position_rob_y]=' ';
        usleep(100000);       // laterale gauche
        AffichageFichier( Lecture);
      }

        LeRobot.position_rob_y++;
        Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
        Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y-1]=' ';



      usleep(100000);
      AffichageFichier( Lecture);
    }
      //si le robot est dans le feu et est porteur de l'extincteur
    if (Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]=='1') {
      Lecture.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]='1';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';
      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]=='1') {
      Lecture.tab[LeRobot.position_rob_x+1][LeRobot.position_rob_y]='1';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';
      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]=='1') {
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y-1]='1';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';
      usleep(100000);
      AffichageFichier( Lecture);
    }else if (Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]=='1') {
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y+1]='1';
      Lecture.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='1';
      usleep(100000);
      AffichageFichier( Lecture);
    }



  return Lecture;
}
map VieRobot(map Lecture){
  Wall_E LeRobot;
  LeRobot.vie=10;
    //Fluctuation de la vie alloué au robot s'il va dans le feu
  if ((Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y]=='1')) {
    LeRobot.vie--;
  }else if(Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y]=='2'){
    LeRobot.vie=LeRobot.vie-2;
  }else if (Lecture.tab[(LeRobot.position_rob_x)][LeRobot.position_rob_y]=='3') {
    LeRobot.vie=LeRobot.vie-3;
  }

  if (LeRobot.vie <=0) {
    printf("Game over" );


  }else {
    printf("Barre de vie: %d", LeRobot.vie );

  }

return Lecture;
}



}

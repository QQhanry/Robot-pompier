#ifndef FONCTION_H
#define FONCTION_H
#include <stdio.h> //insertion des librairies
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define DEPART 'D'
#define WALL 'x'

typedef struct map{  //creation structure map

  char tab[100][52];
  int longueur;
  int largeur;
  int position_ext_x, position_ext_y;
  int position_ent_x, position_ent_y;

}map;

typedef struct ElRobot{ //création structure robot
  int position_rob_x;
  int position_rob_y;
  int orientation;
  int vie ;


}Wall_E;


//creation des différentes fonctions
map  LectureFichier(char *fichier);// fonction qui prend en paramètre une chaîne de caractère et renvoie une variable de type map 
map AffichageFichier(map Lecture);// fonctions qui prennent en paramètre une variable de type map et renvoie une variable de type map
map InitRobot(map Lecture);
map DeplacementBase(map Lecture);
map DeplacementComp(map Lecture);
map DeplacementBase2(map Lecture);
map DeplacementComp2(map Lecture);
map VieRobot(map Lecture);


#endif

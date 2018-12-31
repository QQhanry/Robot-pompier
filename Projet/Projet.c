#include "fonction.h"
                                  //Par Quentin HANRY, CIR1, le 18/05/2018
int main(int argc, char *argv[]) {
  map Affichage;
  Wall_E LeRobot;

  //initialisation des fonctions d'Affichage
  Affichage=LectureFichier(argv[1]);  // parametre du fichier contenant la map
  Affichage=AffichageFichier(Affichage);
  Affichage=InitRobot(Affichage);
  Affichage=VieRobot(Affichage);


  while (Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='P') {//tant que le robot n'a pas trouvé l'extincteur
    if (Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]!='P' ) {
      Affichage=DeplacementBase(Affichage);
      Affichage= DeplacementComp(Affichage);
      if ((Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P')) {
        printf("%c\n",Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y] );
          break;
      }

    }

  }
  Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]='P';
  if (Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]=='P') { // si le robot a pris l'extincteur
    while (Affichage.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]!='1') { // tant qu'il n'a pas trouvé le feu
      if (Affichage.tab[LeRobot.position_rob_x-1][LeRobot.position_rob_y]!='1') {
        Affichage=DeplacementBase2(Affichage);
        if (Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]=='1') { // si réussite, arrêt du programme
          printf("Mission accomplie!\n" );
            break;

        }
        Affichage=DeplacementComp2(Affichage);

        if (Affichage.tab[LeRobot.position_rob_x][LeRobot.position_rob_y]=='1') {
          printf("Mission accomplie!\n" );
            break;

        }
      }
    }
  }


  return 0;
}

#include "affichage_plateau.h"


void carre_couleur(int ligne, int colonne)
{
    /// rectangle de base
    for (int j = 0; j< 10; j++)
        {
            gotoligcol(ligne,colonne);
            printf(" " );
            colonne++;
        }
}

void cases_couleur()
{
    int lig = 14;
    int col = 15;

    /// Affichage rectangle et couleur terrain 1

    Color(0,4);
    carre_couleur(lig,col);
    col = 28;
    carre_couleur(lig,col);
    col = 41;

    /// Affichage rectangle et couleur terrain 2

    Color(0,1);
    carre_couleur(lig,col);
    col = 54;
    carre_couleur(lig,col);
    col = 80;
    carre_couleur(lig,col);
    lig = 49;

    /// Affichage rectangle et couleur terrain 3

    Color(0,14);
    carre_couleur(lig,col);
    col = 54;
    carre_couleur(lig,col);
    col = 41;

    /// Affichage rectangle et couleur terrain 4

    Color(0,8);
    carre_couleur(lig,col);
    col = 15;
    carre_couleur(lig,col);
    col = 2;
    lig = 19;

    /// Affichage rectangle et couleur terrain 5

    Color(0,6);
    carre_couleur(lig,col);
    lig = 29;
    carre_couleur(lig,col);
    lig = 34;
    carre_couleur(lig,col);
    lig = 39;

    /// Affichage rectangle et couleur terrain 6

    Color(0,13);
    carre_couleur(lig,col);
    lig = 44;
    carre_couleur(lig,col);
    col = 93;

    /// Affichage rectangle et couleur terrain 7

    Color(0,2);
    carre_couleur(lig,col);
    lig = 34;
    carre_couleur(lig,col);
    lig = 29;
    carre_couleur(lig,col);
    lig = 24;

    /// Affichage rectangle et couleur terrain 8

    Color(0,11);
    carre_couleur(lig,col);
    lig = 19;
    carre_couleur(lig,col);
}

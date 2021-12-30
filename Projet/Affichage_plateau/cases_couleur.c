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
    /*
    0 : Noir
    1 : Bleu fonc�
    2 : Vert fonc�
    3 : Turquoise
    4 : Rouge fonc�
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris fonc�
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
    */
    int lig = 14;
    int col = 15;

    /// Affichage rectangle et couleur terrain 1

    Color(0,4); /// rouge fonc�
    carre_couleur(lig,col);
    col = 28;
    carre_couleur(lig,col);
    col = 41;

    /// Affichage rectangle et couleur terrain 2

    Color(0,1); /// bleu fonc�
    carre_couleur(lig,col);
    col = 54;
    carre_couleur(lig,col);
    col = 80;
    carre_couleur(lig,col);
    lig = 49;

    /// Affichage rectangle et couleur terrain 3

    Color(0,14); /// jaune
    carre_couleur(lig,col);
    col = 54;
    carre_couleur(lig,col);
    col = 41;

    /// Affichage rectangle et couleur terrain 4

    Color(0,8); /// gris fonc�
    carre_couleur(lig,col);
    col = 15;
    carre_couleur(lig,col);
    col = 2;
    lig = 19;

    /// Affichage rectangle et couleur terrain 5

    Color(0,6); /// vert caca d'oie
    carre_couleur(lig,col);
    lig = 29;
    carre_couleur(lig,col);
    lig = 34;
    carre_couleur(lig,col);
    lig = 39;

    /// Affichage rectangle et couleur terrain 6

    Color(0,13); /// violet 2
    carre_couleur(lig,col);
    lig = 44;
    carre_couleur(lig,col);
    col = 93;

    /// Affichage rectangle et couleur terrain 7

    Color(0,2); /// vert fonc�
    carre_couleur(lig,col);
    lig = 34;
    carre_couleur(lig,col);
    lig = 29;
    carre_couleur(lig,col);
    lig = 24;

    /// Affichage rectangle et couleur terrain 8

    Color(0,11); ///turquoise
    carre_couleur(lig,col);
    lig = 19;
    carre_couleur(lig,col);
}

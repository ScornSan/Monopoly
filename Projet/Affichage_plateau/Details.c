#include "affichage_plateau.h"


void details()
{
    ///angles extérieurs du plateau
    Color(11,15);
    gotoligcol(derniere_ligne,derniere_colonne);
    printf("%c",angle_bas_droite);
    Color(0,15);
    gotoligcol(derniere_ligne,premiere_colonne);
    printf("%c",angle_bas_gauche);
    Color(12,15);
    gotoligcol(premiere_ligne,derniere_colonne);
    printf("%c",angle_haut_droite);

    /// Angles carré noir du milieu
    Color(12,15);
    gotoligcol(deuxieme_ligne,avant_derniere_colonne);
    printf("%c",angle_bas_gauche);
    Color(0,15);
    gotoligcol(avant_derniere_ligne,deuxieme_colonne);
    printf("%c",angle_haut_droite);
    Color(11,15);
    gotoligcol(avant_derniere_ligne,avant_derniere_colonne);
    printf("%c",angle_haut_gauche);

    /// Angles cases spéciales
    Color(11,15);
    gotoligcol(avant_derniere_ligne,derniere_colonne);
    printf("%c",angle_haut_droite);
    Color(0,15);
    gotoligcol(avant_derniere_ligne,premiere_colonne);
    printf("%c",angle_haut_gauche);
    Color(12,15);
    gotoligcol(premiere_ligne,avant_derniere_colonne);
    printf("%c",angle_haut_gauche);

    Color(12,15);
    gotoligcol(deuxieme_ligne,derniere_colonne);
    printf("%c",angle_bas_droite);
    Color(0,15);
    gotoligcol(derniere_ligne,deuxieme_colonne);
    printf("%c",angle_bas_droite);
    Color(11,15);
    gotoligcol(derniere_ligne,avant_derniere_colonne);
    printf("%c",angle_bas_gauche);

    /// details pixels fleche de "lettreD_et_fleche"

    Color(0,9);
    gotoligcol(46 +5,109 - 11);
    printf(" " );
    gotoligcol(46 +5,110- 11);
    printf(" " );

    gotoligcol(50 +5,109- 11);
    printf(" " );
    gotoligcol(50 +5,110- 11);
    printf(" " );

    gotoligcol(47 +5,109- 11);
    printf(" " );
    gotoligcol(47 +5,108- 11);
    printf(" " );

    gotoligcol(49 +5,108- 11);
    printf(" " );
    gotoligcol(48 +5,107- 11);
    printf(" " );

    gotoligcol(49 +5,109- 11);
    printf(" " );
    gotoligcol(48 +5,108- 11);
    printf(" " );
}

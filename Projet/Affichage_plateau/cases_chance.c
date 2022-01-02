#include "affichage_plateau.h"


void cases_chance()
{
    /// carré gris du bas

    int lig = 45;
    for(int j = 0; j < hauteur_case +1 ; j++)
        {
            int col = 27;
            for (int j = 0; j< largeur_case -1; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }

    /// carré gris du haut

    lig = 10;
    for(int j = 0; j < hauteur_case +1 ; j++)
        {
            int col = 66;
            for (int j = 0; j< largeur_case -1; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }

    ///angles extremité du carré gris du bas

    Color(9,15);
    gotoligcol(45,39);
    printf("%c", angle_haut_gauche );
    gotoligcol(45,26);
    printf("%c", angle_haut_droite );
    gotoligcol(50,39);
    printf("%c", angle_bas_gauche );
    gotoligcol(50,26);
    printf("%c", angle_bas_droite );

    /// angles extrémités du carré gris du haut

    Color(9,15);
    gotoligcol(10,78);
    printf("%c", angle_haut_gauche );
    gotoligcol(10,65);
    printf("%c", angle_haut_droite );
    gotoligcol(15,78);
    printf("%c", angle_bas_gauche );
    gotoligcol(15,65);
    printf("%c", angle_bas_droite );

    /// point d'interogation du bas

    Color(0,7);
    gotoligcol(46,31);
    printf("%c", carac_point_interrogation );
    gotoligcol(45,32);
    printf("%c",carac_point_interrogation );
    gotoligcol(45,34);
    printf("%c",carac_point_interrogation );
    gotoligcol(45,33);
    printf("%c", carac_point_interrogation);
    gotoligcol(46,35);
    printf("%c", carac_point_interrogation );
    gotoligcol(47,34);
    printf("%c", carac_point_interrogation );
    gotoligcol(48,33);
    printf("%c",carac_point_interrogation );
    gotoligcol(50,33);
    printf("%c", 0xDF);

    /// point d'interogation du haut

    gotoligcol(11,69);
    printf("%c", carac_point_interrogation);
    gotoligcol(10,70);
    printf("%c", carac_point_interrogation);
    gotoligcol(10,71);
    printf("%c", carac_point_interrogation);
    gotoligcol(10,72);
    printf("%c",carac_point_interrogation );
    gotoligcol(11,73);
    printf("%c",carac_point_interrogation );
    gotoligcol(12,72);
    printf("%c",carac_point_interrogation );
    gotoligcol(13,71);
    printf("%c", carac_point_interrogation);
    gotoligcol(15,71);
    printf("%c", 0xDF);
}

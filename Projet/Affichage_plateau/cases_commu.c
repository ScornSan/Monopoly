#include "affichage_plateau.h"


void cases_commu()
{
    /// carré gris de gauche

    int lig = 21;
    for(int j = 0; j < hauteur_case -1 ; j++)
        {
            int col = 0;
            for (int j = 0; j< largeur_case +1; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }

    /// carré gris de droite

    lig = 36;
    for(int j = 0; j < hauteur_case -1 ; j++)
        {
            int col = 91;
            for (int j = 0; j< largeur_case +1; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }

    ///angles extremité du carré gris de gauche

    Color(9,15);
    gotoligcol(25,0);
    printf("%c", angle_haut_gauche );
    gotoligcol(25,13);
    printf("%c", angle_haut_droite );
    gotoligcol(20,0);
    printf("%c", angle_bas_gauche );
    gotoligcol(20,13);
    printf("%c", angle_bas_droite );

    /// angles extrémités du carré gris de droite

    Color(9,15);
    gotoligcol(40,91);
    printf("%c", angle_haut_gauche );
    gotoligcol(40,104);
    printf("%c", angle_haut_droite );
    gotoligcol(35,91);
    printf("%c", angle_bas_gauche );
    gotoligcol(35,104);
    printf("%c", angle_bas_droite );

    /// lettre C de gauche

    Color(0,7);
    gotoligcol(21,7);
    printf("%c", carac_lettreC_2 );
    gotoligcol(21,8);
    printf("%c",carac_lettreC_2 );
    gotoligcol(22,6);
    printf("%c",carac_lettreC_1 );
    gotoligcol(23,6);
    printf("%c", carac_lettreC_1);
    gotoligcol(24,7);
    printf("%c", carac_lettreC_3 );
    gotoligcol(24,8);
    printf("%c", carac_lettreC_3 );

    /// lettre C de droite

    Color(0,7);
    gotoligcol(36,98);
    printf("%c", carac_lettreC_2 );
    gotoligcol(36,99);
    printf("%c",carac_lettreC_2 );
    gotoligcol(37,97);
    printf("%c",carac_lettreC_1 );
    gotoligcol(38,97);
    printf("%c", carac_lettreC_1);
    gotoligcol(39,98);
    printf("%c", carac_lettreC_3 );
    gotoligcol(39,99);
    printf("%c", carac_lettreC_3 );
}

#include "affichage_plateau.h"

void Color(int cT,int cF)
{
    // fonction d'affichage de couleurs
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,cF*16+cT);
}

void gotoligcol( int lig, int col )
{

HANDLE H= GetStdHandle( STD_OUTPUT_HANDLE );

COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition(H, mycoord );

}
/*
void affichage_carte()
{
    int lig = 15;
    for(int j = 0; j < 15 ; j++)
        {
            int col = 120;
            for (int j = 0; j< 44; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }
    lig = 15;
    for(int j = 0; j < 2 ; j++)
        {
            int col = 121;
            for (int j = 0; j< 22; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf("%c", 0x10);
                    col = col+2;
                }
            col = 120;
            for (int j = 0; j< 22; j++)
                {
                    Color(0,7);
                    gotoligcol(lig,col);
                    printf("%c", 0x11);
                    col = col +2;
                }
            lig = lig +14;
        }

}*/




void affichage_plateau()
{   //passage en plein écran --> écran passe de 120 a 180 colonnes
    lignes();
    colonnes();
    sepa_lignes();
    sepa_colonnes();
    details();
    cases_speciales_lignes();
    cases_speciales_colonnes();
    cases_couleur();
    lettreD_et_fleche();
    logo_prison();
    parking_gratuit();
    cases_chance();
    cases_commu();
    lettreI();
    //affichage_carte();
    gotoligcol(52,premiere_colonne);

}
/*
    0 : Noir
    1 : Bleu foncé
    2 : Vert foncé
    3 : Turquoise
    4 : Rouge foncé
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris foncé
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
    */

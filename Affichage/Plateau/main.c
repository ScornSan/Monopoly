#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define CONSTANTE_10 10
#define CONSTANTE_52 52
#define CONSTANTE_99 99
#define CONSTANTE_22 22
#define CONSTANTE_28 28
#define CONSTANTE_98 98 // DEPART COLONNE DE DROITE



void Color(int cT,int cF) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,cF*16+cT);
}

void gotoligcol( int lig, int col ) {

HANDLE H= GetStdHandle( STD_OUTPUT_HANDLE );

COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition(H, mycoord );

}

void details()
{
    Color(7,15);
    gotoligcol(58,112);
    printf("%c",0xBC);
    Color(0,15);
    gotoligcol(58,0);
    printf("%c",0xC8);
    Color(10,15);
    gotoligcol(10,0);
    printf("%c",0xC9);
    Color(12,15);
    gotoligcol(10,112);
    printf("%c",0xBB);

    Color(10,15);
    gotoligcol(16,14);
    printf("%c",0xBC);
    Color(12,15);
    gotoligcol(16,CONSTANTE_98);
    printf("%c",0xC8);
    Color(0,15);
    gotoligcol(CONSTANTE_52,14);
    printf("%c",0xBB);
    Color(7,15);
    gotoligcol(CONSTANTE_52,CONSTANTE_98);
    printf("%c",0xC9);

    Color(7,15);
    gotoligcol(CONSTANTE_52,112);
    printf("%c",0xBB);
    Color(0,15);
    gotoligcol(CONSTANTE_52,0);
    printf("%c",0xC9);
    Color(10,15);
    gotoligcol(CONSTANTE_10,14);
    printf("%c",0xBB);
    Color(12,15);
    gotoligcol(CONSTANTE_10,CONSTANTE_98);
    printf("%c",0xC9);

    Color(10,15);
    gotoligcol(16,0);
    printf("%c",0xC8);
    Color(12,15);
    gotoligcol(16,112);
    printf("%c",0xBC);
    Color(0,15);
    gotoligcol(58,14);
    printf("%c",0xBC);
    Color(7,15);
    gotoligcol(58,CONSTANTE_98);
    printf("%c",0xC8);
}

void cases_speciales_lignes()
{
    int ligne = CONSTANTE_10;
    for (int i = 0; i<2; i++){
        int col = 1;
        for (int j = 0; j<13; j++)
            {
                Color(10,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
    ligne = CONSTANTE_10;
    for (int i = 0; i<2; i++){
        int col = CONSTANTE_99;
        for (int j = 0; j<13; j++)
            {
                Color(12,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
    ligne = CONSTANTE_52;
    for (int i = 0; i<2; i++){
        int col = 1;
        for (int j = 0; j<13; j++)
            {
                Color(0,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
    ligne = CONSTANTE_52;
    for (int i = 0; i<2; i++){
        int col = CONSTANTE_99;
        for (int j = 0; j<13; j++)
            {
                Color(7,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
}

void cases_speciales_colonnes()
{
    int col = 0;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<5; j++)
            {
                Color(10,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
    col = CONSTANTE_98;
    for (int i = 0; i<2; i++){
        int lig = 53;
        for (int j = 0; j<2; j++)
            {
                Color(7,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
    col = CONSTANTE_98;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<5; j++)
            {
                Color(12,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
    col = 0;
    for (int i = 0; i<2; i++){
        int lig = 53;
        for (int j = 0; j<5; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
}
void sepa_lignes()
{
    int ligne = CONSTANTE_10;
    for (int i = 0; i<2; i++){
        int col = 0;
        for (int j = 0; j<112; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
    ligne = CONSTANTE_22;
    for (int i = 0; i<5; i++){
        int col = 0;
        for (int j = 0; j< 14; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
    ligne = CONSTANTE_22;
    for (int i = 0; i<5; i++){
        int col = CONSTANTE_98;
        for (int j = 0; j< 14; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
    ligne = CONSTANTE_52;
    for (int i = 0; i<2; i++){
        int col = 0;
        for (int j = 0; j<112; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne = ligne + 6;
    }
}

void sepa_colonnes()
{
    int col = 0;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<47; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
    col = CONSTANTE_28;
    for (int i = 0; i<5; i++){
        int lig = 11;
        for (int j = 0; j<5; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
    col = CONSTANTE_28;
    for (int i = 0; i<5; i++){
        int lig = 53;
        for (int j = 0; j<5; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
    col = CONSTANTE_98;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<47; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig = lig +1;
                printf("%c", 0xBA);
            }
        col = col + 14;
    }
}
void lignes()
{
    int lig = CONSTANTE_10;
    for(int i = 0; i < 6; i++)
    {
        int col = 0;
        for (int j = 0; j< 112; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                col++;
            }
        lig++;
    }
    lig = CONSTANTE_52;
    for(int i = 0; i < 6; i++)
    {
        int col = 0;
        for (int j = 0; j< 112; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                col++;
            }
        lig++;
    }
}

void colonnes()
{
    int col = 0;
    for(int i = 0; i < 14; i++)
    {
        int lig = 16;
        for (int j = 0; j< 36; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col++;
    }
    col = CONSTANTE_98;
    for(int i = 0; i < 14; i++)
    {
        int lig = 16;
        for (int j = 0; j< 36; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col++;
    }
}

void affichage_plateau()
{   //passage en plein écran --> écran passe de 120 a 180 colonnes
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    //system("mode con: cols=180 lines=100");
    // prog test taille ecran
    /*for (int i = 0; i< 180; i++){
            Color(0,15);
            gotoligcol(10,col);
            col = col +1;
            printf("%c", " " );
        }*/
    lignes();
    colonnes();
    sepa_lignes();
    sepa_colonnes();
    details();
    cases_speciales_lignes();
    cases_speciales_colonnes();
    gotoligcol(70,0);
}

int main()
{
    affichage_plateau();
    return 0;
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

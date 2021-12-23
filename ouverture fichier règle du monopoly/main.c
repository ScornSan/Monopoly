#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
    Color(11,15);
    gotoligcol(50,104);
    printf("%c",0xBC);
    Color(0,15);
    gotoligcol(50,0);
    printf("%c",0xC8);
    Color(10,15);
    gotoligcol(10,0);
    printf("%c",0xC9);
    Color(12,15);
    gotoligcol(10,104);
    printf("%c",0xBB);

    Color(10,15);
    gotoligcol(15,13);
    printf("%c",0xBC);
    Color(12,15);
    gotoligcol(15,91);
    printf("%c",0xC8);
    Color(0,15);
    gotoligcol(45,13);
    printf("%c",0xBB);
    Color(11,15);
    gotoligcol(45,91);
    printf("%c",0xC9);

    Color(11,15);
    gotoligcol(45,104);
    printf("%c",0xBB);
    Color(0,15);
    gotoligcol(45,0);
    printf("%c",0xC9);
    Color(10,15);
    gotoligcol(10,13);
    printf("%c",0xBB);
    Color(12,15);
    gotoligcol(10,91);
    printf("%c",0xC9);

    Color(10,15);
    gotoligcol(15,0);
    printf("%c",0xC8);
    Color(12,15);
    gotoligcol(15,104);
    printf("%c",0xBC);
    Color(0,15);
    gotoligcol(50,13);
    printf("%c",0xBC);
    Color(11,15);
    gotoligcol(50,91);
    printf("%c",0xC8);
}


void cases_speciales_lignes()
{
    int ligne = 10;
    for (int i = 0; i<2; i++){
        int col = 1;
        for (int j = 0; j<12; j++)
            {
                Color(10,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
    ligne = 10;
    for (int i = 0; i<2; i++){
        int col = 92;
        for (int j = 0; j<12; j++)
            {
                Color(12,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
    ligne = 45;
    for (int i = 0; i<2; i++){
        int col = 1;
        for (int j = 0; j<12; j++)
            {
                Color(0,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
    ligne = 45;
    for (int i = 0; i<2; i++){
        int col = 92;
        for (int j = 0; j<12; j++)
            {
                Color(11,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
}

void cases_speciales_colonnes()
{
    int col = 0;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<4; j++)
            {
                Color(10,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
    col = 91;
    for (int i = 0; i<2; i++){
        int lig = 46;
        for (int j = 0; j<4; j++)
            {
                Color(11,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
    col = 91;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<4; j++)
            {
                Color(12,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
    col = 0;
    for (int i = 0; i<2; i++){
        int lig = 46;
        for (int j = 0; j<4; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
}


void sepa_lignes()
{
    int ligne = 10;
    for (int i = 0; i<2; i++){
        int col = 1;
        for (int j = 0; j<103; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
    ligne = 20;
    for (int i = 0; i<5; i++){
        int col = 1;
        for (int j = 0; j< 13; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
    ligne = 20;
    for (int i = 0; i<5; i++){
        int col = 91;
        for (int j = 0; j< 13; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
    ligne = 45;
    for (int i = 0; i<2; i++){
        int col = 1;
        for (int j = 0; j<103; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + 5;
    }
}

void sepa_colonnes()
{
    int col = 0;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<39; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
    col = 26;
    for (int i = 0; i<5; i++){
        int lig = 11;
        for (int j = 0; j<4; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
    col = 26;
    for (int i = 0; i<5; i++){
        int lig = 46;
        for (int j = 0; j<4; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
    col = 91;
    for (int i = 0; i<2; i++){
        int lig = 11;
        for (int j = 0; j<39; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + 13;
    }
}

void lignes()
{
    int lig = 10;
    for(int i = 0; i < 5; i++)
    {
        int col = 1;
        for (int j = 0; j< 103; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                col++;
            }
        lig++;
    }
    lig = 45;
    for(int i = 0; i < 5; i++)
    {
        int col = 0;
        for (int j = 0; j< 104; j++)
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
    for(int i = 0; i < 13; i++)
    {
        int lig = 15;
        for (int j = 0; j< 30; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col++;
    }
    col = 91;
    for(int i = 0; i < 13; i++)
    {
        int lig = 15;
        for (int j = 0; j< 30; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col++;
    }
}

int main()
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
    gotoligcol(55,0);
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

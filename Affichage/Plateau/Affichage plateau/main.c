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
    gotoligcol(58,112);
    printf("%c",0xBC);
    gotoligcol(58,0);
    printf("%c",0xC8);
    gotoligcol(10,0);
    printf("%c",0xC9);
    gotoligcol(10,112);
    printf("%c",0xBB);
    int ligne_reconf = 16;
    for (int i = 0; i<2; i++){
        int col = 15;
        for (int j = 0; j<83; j++)
            {
                Color(9,15);
                gotoligcol(ligne_reconf,col);
                col = col +1;
                printf("%c", 0xCD);
            }
        ligne_reconf = ligne_reconf + 36;
    }
}

void carre_noir()
{
    int ligne_noir = 17;
    for (int i = 0; i<35;i++)
    {
        int col = 15;
        for (int j = 0; j< 83; j++)
            {
                Color(0,0);
                gotoligcol(ligne_noir,col);
                printf("%c", " " );
                col++;
            }
        ligne_noir++;
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
    int lig = 10;
    for (int i = 0; i< 48; i++)
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
    int ligne = 10;
    for (int i = 0; i<9; i++){
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
    int col = 0;
    for (int i = 0; i<9; i++){
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
    details();
    carre_noir();
    gotoligcol(70,0);
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

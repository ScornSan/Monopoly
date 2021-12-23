#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define largeur_case 13
#define hauteur_case 5
#define derniere_colonne 104
#define premiere_colonne 0
#define deuxieme_colonne 13
#define deuxieme_ligne 15
#define avant_derniere_colonne 91
#define avant_derniere_colonne_gain 92
#define avant_derniere_ligne 45
#define avant_derniere_ligne_gain 46
#define derniere_ligne 50
#define premiere_ligne_gain 11
#define premiere_ligne 10
#define troisieme_ligne 20
#define nombre_lignes_a_faire 2
#define nombre_lignes_a_faire_gain 4
#define nombre_lignes_gain 30
#define nombre_colonnes_gain 12
#define jusque_repetition_ligne 39
#define jusque_repetition_colonne 103


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
    gotoligcol(derniere_ligne,derniere_colonne);
    printf("%c",0xBC);
    Color(0,15);
    gotoligcol(derniere_ligne,premiere_colonne);
    printf("%c",0xC8);
    Color(10,15);
    gotoligcol(premiere_ligne,premiere_colonne);
    printf("%c",0xC9);
    Color(12,15);
    gotoligcol(premiere_ligne,derniere_colonne);
    printf("%c",0xBB);

    Color(10,15);
    gotoligcol(deuxieme_ligne,deuxieme_colonne);
    printf("%c",0xBC);
    Color(12,15);
    gotoligcol(deuxieme_ligne,avant_derniere_colonne);
    printf("%c",0xC8);
    Color(0,15);
    gotoligcol(avant_derniere_ligne,deuxieme_colonne);
    printf("%c",0xBB);
    Color(11,15);
    gotoligcol(avant_derniere_ligne,avant_derniere_colonne);
    printf("%c",0xC9);

    Color(11,15);
    gotoligcol(avant_derniere_ligne,derniere_colonne);
    printf("%c",0xBB);
    Color(0,15);
    gotoligcol(avant_derniere_ligne,premiere_colonne);
    printf("%c",0xC9);
    Color(10,15);
    gotoligcol(premiere_ligne,deuxieme_colonne);
    printf("%c",0xBB);
    Color(12,15);
    gotoligcol(premiere_ligne,avant_derniere_colonne);
    printf("%c",0xC9);

    Color(10,15);
    gotoligcol(deuxieme_ligne,premiere_colonne);
    printf("%c",0xC8);
    Color(12,15);
    gotoligcol(deuxieme_ligne,derniere_colonne);
    printf("%c",0xBC);
    Color(0,15);
    gotoligcol(derniere_ligne,deuxieme_colonne);
    printf("%c",0xBC);
    Color(11,15);
    gotoligcol(derniere_ligne,avant_derniere_colonne);
    printf("%c",0xC8);
}


void cases_speciales_lignes()
{
    int ligne = premiere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = 1;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(10,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
    ligne = premiere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = avant_derniere_colonne_gain;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(12,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
    ligne = avant_derniere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = 1;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(0,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
    ligne = avant_derniere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = avant_derniere_colonne_gain;
        for (int j = 0; j<nombre_colonnes_gain; j++)
            {
                Color(11,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
}

void cases_speciales_colonnes()
{
    int col = premiere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = premiere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(10,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
    col = avant_derniere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = avant_derniere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(11,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
    col = avant_derniere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = premiere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(12,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
    col = premiere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = avant_derniere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
}


void sepa_lignes()
{
    int ligne = premiere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = 1;
        for (int j = 0; j<jusque_repetition_colonne; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
    ligne = troisieme_ligne;
    for (int i = 0; i<hauteur_case; i++){
        int col = 1;
        for (int j = 0; j< largeur_case; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
    ligne = troisieme_ligne;
    for (int i = 0; i<hauteur_case; i++){
        int col = avant_derniere_colonne;
        for (int j = 0; j< largeur_case; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
    ligne = avant_derniere_ligne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int col = 1;
        for (int j = 0; j<jusque_repetition_colonne; j++)
            {
                Color(9,15);
                gotoligcol(ligne,col);
                col++;
                printf("%c", 0xCD);
            }
        ligne = ligne + hauteur_case;
    }
}

/*void sepa_colonnes()
{
    int col = premiere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = premiere_ligne_gain;
        for (int j = 0; j<jusque_repetition_ligne; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
    col = 26;
    for (int i = 0; i<hauteur_case; i++){
        int lig = premiere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
    col = 26;
    for (int i = 0; i<hauteur_case; i++){
        int lig = avant_derniere_ligne_gain;
        for (int j = 0; j<nombre_lignes_a_faire_gain; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
    col = avant_derniere_colonne;
    for (int i = 0; i<nombre_lignes_a_faire; i++){
        int lig = premiere_ligne_gain;
        for (int j = 0; j<jusque_repetition_ligne; j++)
            {
                Color(9,15);
                gotoligcol(lig,col);
                lig++;
                printf("%c", 0xBA);
            }
        col = col + largeur_case;
    }
}*/

void lignes()
{
    int lig = premiere_ligne;
    for(int i = 0; i < hauteur_case; i++)
    {
        int col = 1;
        for (int j = 0; j< jusque_repetition_colonne; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                col++;
            }
        lig++;
    }
    lig = avant_derniere_ligne;
    for(int i = 0; i < hauteur_case; i++)
    {
        int col = premiere_colonne;
        for (int j = 0; j< derniere_colonne; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                col++;
            }
        lig++;
    }
}

/*void colonnes()
{
    int col = premiere_colonne;
    for(int i = 0; i < largeur_case; i++)
    {
        int lig = deuxieme_ligne;
        for (int j = 0; j< nombre_lignes_gain; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col++;
    }
    col = avant_derniere_colonne;
    for(int i = 0; i < largeur_case; i++)
    {
        int lig = deuxieme_ligne;
        for (int j = 0; j< nombre_lignes_gain; j++)
            {
                Color(0,15);
                gotoligcol(lig,col);
                printf("%c", " " );
                lig++;
            }
        col++;
    }
}*/

int main()
{   //passage en plein écran --> écran passe de 120 a 180 colonnes
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    //system("mode con: cols=180 lines=100");
    // prog test taille ecran
    /*for (int i = 0; i< 180; i++){
            Color(0,15);
            gotoligcol(premiere_ligne,col);
            col = col +1;
            printf("%c", " " );
        }*/
    lignes();
    //colonnes();
    sepa_lignes();
    //sepa_colonnes();
    details();
    cases_speciales_lignes();
    cases_speciales_colonnes();
    gotoligcol(52,premiere_colonne);
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

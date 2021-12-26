#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "affichage_choix.h"
#include "echap.h"
#include "affichage_menu.h"
#include "structure_joueur.h"


void couleur(int couleurTexte,int couleurFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurFond*16+couleurTexte);
}

void gotoligcol( int lig, int col )  // fonction curseur
{
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


int main()
{
    affichage_Menu();
    fflush(stdin);
}


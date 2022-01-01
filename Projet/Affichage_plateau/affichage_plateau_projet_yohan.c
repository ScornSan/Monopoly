#include "affichage_plateau.h"

void Color(int cT,int cF)
{
    // fonction d'affichage de couleurs
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,cF*16+cT);
}

void affichage_plateau()
{
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
    gotoligcol(0,premiere_colonne);
    Color(15,0);
    position(premiere_ligne, derniere_colonne + 20);
    printf("Appuyer sur [M] pour acceder au menu");
    echap();

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

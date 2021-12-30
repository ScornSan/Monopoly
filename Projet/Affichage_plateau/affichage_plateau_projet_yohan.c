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

}

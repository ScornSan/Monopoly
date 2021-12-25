#ifndef AFFICHAGE_PLATEAU_H_INCLUDED
#define AFFICHAGE_PLATEAU_H_INCLUDED


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
#define carac_point_interrogation 0xFE
#define angle_haut_droite 0xBB
#define angle_haut_gauche 0xC9
#define angle_bas_droite 0xBC
#define angle_bas_gauche 0xC8
#define carac_lettreC_1 0xDB
#define carac_lettreC_2 0xDC
#define carac_lettreC_3 0xDF

void Color(int cT,int cF);
void gotoligcol( int lig, int col );


#endif // AFFICHAGE_PLATEAU_H_INCLUDED

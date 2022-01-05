#include "affichage.h"
#include "../Structures/structure_joueur.h"

void liaison_memoire_affichage(int repere[4]/*t_carte terrain[][3]*/,int a,int b)
{
    switch(a)
    {
    case 0:
        repere[2] = 0;
        repere[3] = 12;
        switch(b)
        {
        case 0:
            repere[0] = 45;
            repere[1] = 78;
            break;
        case 1:
            repere[0] = 45;
            repere[1] = 52;
            break;
        }
        break;
    case 1:
        repere[2] = 0;
        repere[3] = 8;
        switch(b)
        {
        case  0:
            repere[0] = 45;
            repere[1] = 39;
            break;
        case  1:
            repere[0] = 45;
            repere[1] = 13;
            break;
        }
        break;
    case 2:
        repere[2] = 0;
        repere[3] = 13;
        switch(b)
        {
        case 0 :
            repere[0] = 40;
            repere[1] = 0;
            break;
        case  1:
            repere[0] = 35;
            repere[1] = 0;
            break;
        }
        break;
    case 3:
        repere[2] = 0;
        repere[3] = 6;
        switch(b)
        {
        case 0:
            repere[0] = 30;
            repere[1] = 0;
            break;
        case 1:
            repere[0] = 25;
            repere[1] = 0;
            break;
        case 2:
            repere[0] = 15;
            repere[1] = 0;
            break;
        }
        break;
    case 4:
        repere[2] = 0;
        repere[3] = 4;
        switch(b)
        {
        case 0 :
            repere[0] = 10;
            repere[1] = 13;
            break;
        case 1 :
            repere[0] = 10;
            repere[1] = 26;
            break;
        }
        break;
    case 5:
        repere[2] = 0;
        repere[3] = 1;
        switch(b)
        {
        case 0 :
            repere[0] = 10;
            repere[1] = 39;
            break;
        case 1:
            repere[0] = 10;
            repere[1] = 52;
            break;
        case 2:
            repere[0] = 10;
            repere[1] = 78;
            break;
        }
        break;
    case 6:
        repere[2] = 0;
        repere[3] = 11;
        switch(b)
        {
        case 0 :
            repere[0] = 15;
            repere[1] = 91;
            break;
        case 1:
            repere[0] = 20;
            repere[1] = 91;
            break;
        }
        break;
    case 7:
        repere[2] = 0;
        repere[3] = 2;
        switch(b)
        {
        case 0 :
            repere[0] = 25;
            repere[1] = 91;
            break;
        case 1 :
            repere[0] = 30;
            repere[1] = 91;
            break;
        case 2 :
            repere[0] = 40;
            repere[1] = 91;
            break;
        }
        break;
    }
}

void affichage_maisons(int repere[], int a)
{
    Color(repere[2],repere[3]);
    for (int i = 0 ; i < a ;i++)
    {
        gotoligcol(repere[0] + AJUSTEMENT_LIGNE, repere[1] + AJUSTEMENT_COLONNE + (2*i));
        printf("%c",0x0C);
    }
    Color(0,15);
}

void affichage_hotel(int repere[4]/*,t_carte terrain[][3]*/)
{
    Color(repere[2],repere[3]);
    gotoligcol(repere[0] + AJUSTEMENT_LIGNE , repere[1] + AJUSTEMENT_COLONNE) ;
    printf("%c",0x0F);
    Color(0,15);
}



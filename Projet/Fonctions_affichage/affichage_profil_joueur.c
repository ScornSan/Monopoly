#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

void affichage_pseudo_joueurs(int nb_joueurs, t_joueur joueur[] )
{
    int ligne = 1;
    int i;
    int colonne = 105;
    Color(15,0);
    for(i = 0; i< nb_joueurs; i++)
    {
        gotoligcol(ligne, colonne + 9-(strlen(joueur[i].pseudo)/2));
        printf("%s", joueur[i].pseudo);
        colonne += 19;
    }
    ligne = 3;
    colonne = 124;
    for (i = 0; i < nb_joueurs -1; i++)
    {
        for(int j = 0; j < 49; j++)
        {
            gotoligcol(ligne,colonne + i*19);
            printf("%c",0xB3);
            colonne--;
            gotoligcol(ligne,colonne + i*19);
            printf("%c", 0xB3);
            colonne++;
            ligne++;
        }
        ligne = 3;
    }
}

void affichage_argent_joueurs(t_joueur joueurs[], int id_joueurs)
{
    if (joueurs[id_joueurs].argent < 1000 && joueurs[id_joueurs].argent > 500)
    {
        Color(14,0);
    }
    else if (joueurs[id_joueurs].argent < 500)
    {
        Color(4,0);
    }
    else
    {
        Color(10,0);
    }
    int ligne = 2;
    int colonne = 105;
    gotoligcol(ligne, colonne + 8 + (id_joueurs * 19));
    printf("%d", joueurs[id_joueurs].argent);
}


void affichage_carte( int id_joueur, t_carte terrain[][3], int id_carte[], int a , int b)
{
    /// Dessin de la carte
    /// fond
    Color(0,7);
    int colonne = 106;
    int lig = 4 + (id_carte[id_joueur] * 10);
    for(int j = 0; j < 8; j++)
        {
            int col = colonne + ( id_joueur * 19);
            for (int j = 0; j< 17; j++)
                {
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }
    /// Caractere haut et bas
    lig = 4 +(id_carte[id_joueur] * 10);
    switch(a)
    {
    case 0 :
        Color(14,7);
        break;
    case 1 :
        Color(8,7);
        break;
    case 2 :
        Color(13,7);
        break;
    case 3 :
        Color(6,7);
        break;
    case 4 :
        Color(4,7);
        break;
    case 5 :
        Color(1,7);
        break;
    case 6 :
        Color(3,7);
        break;
    case 7 :
        Color(10,7);
        break;
    }
    for(int j = 0; j < 2 ; j++)
    {
        int col = colonne + ( id_joueur * 19) +1;
        for (int j = 0; j< 8; j++)
            {
                gotoligcol(lig,col);
                printf("%c", 0x10);
                col = col+2;
            }
        col = colonne + ( id_joueur * 19);
        for (int j = 0; j< 9; j++)
            {
                gotoligcol(lig,col);
                printf("%c", 0x11);
                col = col +2;
            }
        lig = lig + 8;
    }
    Color(0,7);
    /// Fin du dessin de la carte

    /// Infos carte
    Color(0,7);
    gotoligcol(4 +( id_carte[id_joueur] * 10) +1, colonne + ( id_joueur * 19)+6);
    printf("%s\n",terrain[a][b].nom);
    gotoligcol(4 +( id_carte[id_joueur] * 10) +3, colonne + ( id_joueur * 19)+1);
    printf("Loyer: %d$\n",terrain[a][b].prix_loyer);
    gotoligcol(4 +( id_carte[id_joueur] * 10) +5, colonne + ( id_joueur * 19)+1);
    printf("Hypotheque: %d$\n",terrain[a][b].val_hypotheque);
    gotoligcol(4 +( id_carte[id_joueur] * 10) +7, colonne + ( id_joueur * 19)+1);
    printf("Maisons: %d\n",terrain[a][b].nb_maison);
    Color(15,0);
}

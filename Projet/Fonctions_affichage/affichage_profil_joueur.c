#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

void affichage_pseudo_joueurs(int nb_joueurs, t_joueur joueur[] )
{
    int ligne = 10;
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
    int ligne = 11;
    int colonne = 105;
    if (joueurs[id_joueurs].argent < 1000 && joueurs[id_joueurs].argent > 500)
    {
        gotoligcol(ligne, colonne + 8 + (id_joueurs * 19));
        printf("    ");
        Color(14,0);
    }
    else if (joueurs[id_joueurs].argent < 500)
    {
        gotoligcol(ligne, colonne + 8 + (id_joueurs * 19));
        printf("    ");
        Color(4,0);
    }
    else
    {
        gotoligcol(ligne, colonne + 8 + (id_joueurs * 19));
        printf("    ");
        Color(10,0);
    }
    gotoligcol(ligne, colonne + 8 + (id_joueurs * 19));
    printf("%d", joueurs[id_joueurs].argent);
}


void affichage_carte(int repere[], int id_joueur, t_carte terrain[][3], int a , int b)
{
    /// Dessin de la carte
    /// fond
    Color(0,7);
    int colonne = 106;
    int lig = 8 + (terrain[a][b].id_carte[id_joueur] * 14 - 10);
    for(int j = 0; j < 12; j++)
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
    lig = 8 +(terrain[a][b].id_carte[id_joueur] * 14 - 10);
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
        lig = lig + 12;
    }
    Color(0,7);
    /// Fin du dessin de la carte

    /// Infos carte
    Color(0,7);
    placement_script_carte(strlen(terrain[a][b].nom), id_joueur, terrain, a, b);
    printf("%s",terrain[a][b].nom);
    gotoligcol(8 +( terrain[a][b].id_carte[id_joueur] * 14 - 10) +3, colonne + ( id_joueur * 19)+1);
    printf("Loyer: %d$",terrain[a][b].prix_loyer);
    gotoligcol(8 +( terrain[a][b].id_carte[id_joueur] * 14 - 10) +5, colonne + ( id_joueur * 19)+1);
    if (terrain[a][b].hypotheque == true)
    {
        printf("Prix Rachat: %d$",terrain[a][b].prix_rachat);
    }
    else
    {
        printf("Hypotheque: %d$",terrain[a][b].val_hypotheque);
    }
    gotoligcol(8 +( terrain[a][b].id_carte[id_joueur] * 14 - 10) +7, colonne + ( id_joueur * 19)+1);
    printf("Maisons: %d",terrain[a][b].nb_maison);
    gotoligcol(8 +( terrain[a][b].id_carte[id_joueur] * 14 - 10) +9, colonne + ( id_joueur * 19)+1);
    printf("Prix Maison:%d$",terrain[a][b].prix_maison);
    gotoligcol(8 +( terrain[a][b].id_carte[id_joueur] * 14 - 10) +11, colonne + ( id_joueur * 19)+1);
    printf("Prix Hotel: %d$", terrain[a][b].prix_maison + 100);
    Color(15,0);
}

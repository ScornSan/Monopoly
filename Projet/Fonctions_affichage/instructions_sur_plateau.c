#include "../Affichage_plateau/affichage_plateau.h"
#include "../Structures/structure_joueur.h"
#include "affichage.h"

void placement_script(int longueur, int a)
{
    /// int longueur est la longueur de la chaine de carac a afficher
    /// int a repr�sentent le nombre de ligne a afficher en 1 seule fois avant l'affichage du carr� noir pour clear

    int ligne = 29;          /// centre vertical du carr� noir           /// centre toujours le texte a afficher peut importe sa longeur horizontalement
                                            /// 'nb' + 10, le +10 equivaut a la taille de la chaine "Maison 3.2" par ex
    int colonne = 51-((longueur)/2);        /// centre toujours le texte a afficher peut importe sa longeur horizontalement
    gotoligcol(ligne + a,colonne);    /// place le curseur pour que le texte en sortie de fonction s'affiche au bon endroit
}

void placement_script_carte(int longueur,int id_joueur, t_carte terrain[][3], int a , int b )
{
    int colonne =  115 - longueur/2 - 1.5;
    int ligne = ( -1 +(terrain[a][b].id_carte[id_joueur] * 14)) ;
    gotoligcol(ligne, colonne + (id_joueur * 19)+1);
}

void affichage_nom_terrain(int repere[], t_carte terrain[][3])
{
    Color(0,15);
    int nb_cartes;
    for (int i = 0; i < GROUPES_CARTES; i++)
    {
        if (i % 2 == 0 || i == 1)
        {
            nb_cartes = 2;
        }
        else
        {
            nb_cartes = 3;
        }
        for (int j = 0; j < nb_cartes; j++)
        {
            liaison_memoire_affichage(repere, i, j);
            longueur = strlen(terrain[i][j].nom);
            gotoligcol(repere[0] + 1 , repere[1] + 7 - (longueur/2));
            printf("%s", terrain[i][j].nom);
        }
    }
    Color(12,15);
    gotoligcol(11, 93);
    printf(" ALLEZ EN");
    gotoligcol(13, 94);
    printf(" PRISON");
}

void affichage_prix_terrain(int repere[], t_carte terrain[][3])
{
    Color(0,15);
    int nb_cartes;
    for (int i = 0; i < GROUPES_CARTES; i++)
    {
        if (i % 2 == 0 || i == 1)
        {
            nb_cartes = 2;
        }
        else
        {
            nb_cartes = 3;
        }
        for (int j = 0; j < nb_cartes; j++)
        {
            liaison_memoire_affichage(repere, i, j);
            if (terrain[i][j].hypotheque == true)
            {
                gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE -1);
                effacement_perso(15, 1, 11, repere[0] + AJUSTEMENT_LIGNE -1, repere[1] + AJUSTEMENT_COLONNE-1);
                gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE -1);
                Color(0,15);
                printf("Hypothequee");
            }
            else if (terrain[i][j].prop_achete == true)
            {
                gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE +2);
                effacement_perso(15, 1, 11, repere[0] + AJUSTEMENT_LIGNE -1, repere[1] + AJUSTEMENT_COLONNE -1);
                gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE +2);
                Color(0,15);
                printf("ACHETE");
            }
            else
            {
                if (terrain[i][j].prix_achat < 100)
                {
                    gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE +4);
                    effacement_perso(15, 1, 10, repere[0] + AJUSTEMENT_LIGNE -1, repere[1] + AJUSTEMENT_COLONNE-1);
                    gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE +4);
                    Color(0,15);
                    printf("%d$", terrain[i][j].prix_achat);
                }
                else
                {
                    gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE +3);
                    effacement_perso(15, 1, 11, repere[0] + AJUSTEMENT_LIGNE -1, repere[1] + AJUSTEMENT_COLONNE-1);
                    gotoligcol(repere[0] + AJUSTEMENT_LIGNE -1 , repere[1] + AJUSTEMENT_COLONNE +3);
                    Color(0,15);
                    printf("%d$", terrain[i][j].prix_achat);
                }
            }
        }
    }
}

void connaissance_position_curseur(int tab[])
{
    HANDLE win;

    CONSOLE_SCREEN_BUFFER_INFO coninfo;

    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);

    tab[1] = (coninfo.dwCursorPosition.X)-1;
    tab[0] = coninfo.dwCursorPosition.Y;

}


void position_choix(int longueur,int a, char chaine1[], char chaine2[], char chaine3[], char chaine4[])
{
    //int x = coninfo.dwCursorPosition.X;
    //int y = coninfo.dwCursorPosition.Y;
    int ligne = 33 + a;
    int colonne = 51-((longueur/4)+2);
    gotoligcol(ligne,colonne);
    printf("%s",chaine1);
    gotoligcol(ligne +1,colonne-4);
    printf("-->[%s]",chaine3);
    colonne = 51+((longueur/4)-2);
    gotoligcol(ligne,colonne);
    printf("%s",chaine2);
    gotoligcol(ligne+1,colonne-4);
    printf("-->[%s]",chaine4);
}


void carre_noir()
{
    Color(0,0);
    int lig = 16;
    for(int j = 0; j < 29 ; j++)
        {
            int col = 14;
            for (int j = 0; j< 77; j++)
                {
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }
    Color(15,0);
}

void effacement_perso(int color, int nb_lignes, int nb_colonnes, int depart_lig, int depart_col)
{
    Color(0,color);
    //int lig = depart_lig;
    for(int j = 0; j < nb_lignes ; j++)
        {
            //int col = depart_col;
            for (int j = 0; j< nb_colonnes; j++)
                {
                    gotoligcol(depart_lig, depart_col);
                    printf(" " );
                    depart_col++;
                }
            depart_lig++;
        }
    Color(15,0);
}

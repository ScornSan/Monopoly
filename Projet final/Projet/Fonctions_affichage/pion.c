#include "../Structures/structure_joueur.h"
#include "../Affichage_Plateau_2_ASSO/affichage_plateau.h"

//void carre_noir

void affichage_carte(int ligne, int colonne,t_carte terrain[][3],int a , int b)
{
    Color(0,7);
    int lig = ligne;
    for(int j = 0; j < 15 ; j++)
        {
            int col = colonne;
            for (int j = 0; j< 22; j++)
                {
                    gotoligcol(lig,col);
                    printf(" " );
                    col++;
                }
            lig++;
        }
    lig = ligne;
    for(int j = 0; j < 2 ; j++)
        {
            int col = colonne +1;
            for (int j = 0; j< 11; j++)
                {
                    gotoligcol(lig,col);
                    printf("%c", 0x10);
                    col = col+2;
                }
            col = colonne;
            for (int j = 0; j< 11; j++)
                {
                    gotoligcol(lig,col);
                    printf("%c", 0x11);
                    col = col +2;
                }
            lig = lig + 14;
        }
        Color(0,7);
        gotoligcol(ligne +2, colonne+6);
        printf("%s\n",terrain[a][b].nom);
        gotoligcol(ligne +4, colonne+1);
        printf("Loyer : %d$\n",terrain[a][b].prix_loyer);
        gotoligcol(ligne +6, colonne+1);
        printf("Hypotheque : %d$\n",terrain[a][b].prix_hypotheque);
        gotoligcol(ligne +8, colonne+1);
        printf("Maisons : %d\n",terrain[a][b].nb_maison);
}


/*void emplacement_carte()
{
    creation_carte(15, 120);
    creation_carte(31, 120);
    creation_carte(47, 120);
}*/

#include "../Structures/structure_joueur.h"
#include "../Affichage_Plateau_2/affichage_plateau.h"



void placement_script(int longueur, int a)
{
    /// int longueur est la longueur de la chaine de carac a afficher
    /// int a représentent le nombre de ligne a afficher en 1 seule fois avant l'affichage du carré noir pour clear
    int ligne = 29;          /// centre vertical du carré noir
    int colonne = 51-((longueur)/2);        /// centre toujours le texte a afficher peut importe sa longeur horizontalement
    gotoligcol(ligne + a,colonne);    /// place le curseur pour que le texte en sortie de fonction s'affiche au bon endroit
}



void connaissance_position_curseur()
{
    HANDLE win;

    CONSOLE_SCREEN_BUFFER_INFO coninfo;

    printf ("\n\n\n\ABCDEF");

    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);

    int x = coninfo.dwCursorPosition.X;
    int y = coninfo.dwCursorPosition.Y;

}

void position_choix(int longueur)
{
    int ligne = 33;
    int colonne = 51-((longueur/4)+2);
    gotoligcol(ligne,colonne);
    printf("Oui");
    gotoligcol(ligne +1,colonne-4);
    printf("-->[ENTRER]");
    colonne = 51+((longueur/4)-2);
    gotoligcol(ligne,colonne);
    printf("Non");
    gotoligcol(ligne+1,colonne-4);
    printf("-->[Autre]");

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
        Color(15,0);
}


/*void emplacement_carte()
{
    creation_carte(15, 120);
    creation_carte(31, 120);
    creation_carte(47, 120);
}*/

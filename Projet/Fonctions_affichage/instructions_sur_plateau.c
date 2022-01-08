#include "../Affichage_plateau/affichage_plateau.h"
#include "../Structures/structure_joueur.h"

void placement_script(int longueur, int a)
{
    /// int longueur est la longueur de la chaine de carac a afficher
    /// int a représentent le nombre de ligne a afficher en 1 seule fois avant l'affichage du carré noir pour clear

    int ligne = 29;          /// centre vertical du carré noir           /// centre toujours le texte a afficher peut importe sa longeur horizontalement
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


void connaissance_position_curseur(int tab[])
{
    HANDLE win;

    CONSOLE_SCREEN_BUFFER_INFO coninfo;

    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);

    tab[1] = (coninfo.dwCursorPosition.X)-1;
    tab[0] = coninfo.dwCursorPosition.Y;

}


void position_choix(int longueur,int a, char chaine1[100], char chaine2[100], char chaine3[100], char chaine4[100])
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

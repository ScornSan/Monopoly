#include "structure_joueur.h"

int demander_nb_joueur()
{
    // demande le nombre de joueurs
    int nb_joueurs = 0;
    //int nb_joueurs = 2; /// TODO remettre à 0
    int repet = -1;
    while (nb_joueurs != 2 && nb_joueurs != 3 && nb_joueurs != 4)
    {
        repet+= 1;
        char chaine[100] = "A combien souhaitez-vous jouer ?";
        if (repet == 11)
        {
            carre_noir();
            repet = 0;
        }
        placement_script(chaine,repet);
        printf("%s",chaine);
        GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
        int y = coninfo.dwCursorPosition.Y;
        gotoligcol(y +1,51);
        fflush(stdin);
        scanf("%d", &nb_joueurs);

    }
    return nb_joueurs; // on retourne avec -1 car la valeur qu'on retourne va nous servir pour les indices
}


void creation_joueurs(t_joueur joueur[], int nombre_joueurs)
{
    // tableau de structures, nombre de struct = nombre de joueurs
    // remplissage
    int repet = 0;
    for (int x = 0; x < nombre_joueurs; x++)
    {
        repet += 1;
        char chaine[100] = "Joueur %d, entrez votre pseudo : ";
        placement_script(chaine,repet);
        printf("%s",chaine, x + 1);
        fflush(stdin);
        gets(&joueur[x].pseudo);
        joueur[x].argent = 1500;
        joueur[x].position = 0;
    }
}

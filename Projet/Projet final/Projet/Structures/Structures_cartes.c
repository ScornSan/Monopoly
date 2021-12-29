#include "structure_joueur.h"

void remplissages_cartes(t_carte carte[][3])
{
    int nb_cartes;
    // le nombre de quartiers dans le jeu est une constante de 8
    /// on définit la taille max d'un groupe de cartes, 2 ou 3 selon les groupes
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
            // le prix de départ est calculé par rapport au groupe de la carte, puis son niveau dans le groupe
            // on parcours selon le groupe de quartier puis selon la carte, 0, 1 voir 2 du quartier i
            /// on définit le prix d'achat du terrain et du loyer nu
            carte[i][j].prix_achat = (j * 10) + (i * 20) + 20;
            carte[i][j].prop_achete = false;
            carte[i][j].hypotheque = false;
            carte[i][j].val_hypotheque = (int)(carte[i][j].prix_achat / 2); // valeur de l'hypotheque est le prix / 2
            carte[i][j].prix_rachat_hypotheque = carte[i][j].prix_achat * 1.1; // 10% du prix
            carte[i][j].nb_maison = 0; // terrain nu au départ, 0 maisons
            if (nb_cartes == 2 || i == 1)
            {
                carte[i][j].prix_loyer = i*4 + j + (carte[i][j].prix_achat / 10);
            }
            else
            {
                carte[i][j].prix_loyer = i*4 + j + (carte[i][j].prix_achat / 10) - 2;
            }
            if (i == 0 || i == 1)
            {
                carte[i][j].prix_maison = 50;
            }
            if (i == 2 || i == 3)
            {
                carte[i][j].prix_maison = 100;
            }
            if (i == 4 || i == 5)
            {
                carte[i][j].prix_maison = 150;
            }
            if (i == 6 || i == 7)
            {
                carte[i][j].prix_maison = 200;
            }

        }
    }
    /// On va maintenant définir en dur le nombre de chaque terrain
    //chaine = p_carte;
    carte[0][0].nom = "Maison 1.1";
    carte[0][1].nom = "Maison 1.2";
    carte[1][0].nom = "Maison 2.1";
    carte[1][1].nom = "Maison 2.2";
    carte[2][0].nom = "Maison 3.1";
    carte[2][1].nom = "Maison 3.2";
    carte[3][0].nom = "Maison 4.1";
    carte[3][1].nom = "Maison 4.2";
    carte[3][2].nom = "Maison 4.3";
    carte[4][0].nom = "Maison 5.1";
    carte[4][1].nom = "Maison 5.2";
    carte[5][0].nom = "Maison 6.1";
    carte[5][1].nom = "Maison 6.2";
    carte[5][2].nom = "Maison 6.3";
    carte[6][0].nom = "Maison 7.1";
    carte[6][1].nom = "Maison 7.2";
    carte[7][0].nom = "Maison 8.1";
    carte[7][1].nom = "Maison 8.2";
    carte[7][2].nom = "Maison 8.3";
}


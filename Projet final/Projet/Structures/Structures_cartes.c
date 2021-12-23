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
            if (nb_cartes == 2 || i == 1)
            {
                carte[i][j].prix_loyer = i*4 + j + (carte[i][j].prix_achat / 10);
            }
            else
            {
                carte[i][j].prix_loyer = i*4 + j + (carte[i][j].prix_achat / 10) - 2;
            }

        }
        printf("%d\n", carte[i][0].prix_achat);
        printf("%d\n", carte[i][1].prix_achat);
        printf("%d\n", carte[i][2].prix_achat);
    }
}

#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structure_joueur/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int id_joueur)
{
    int de1, de2;
    int nb_lancer = 0;
    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || ((de1 == de2)))
    {
        printf("C'est au joueur %d de jouer ! Appuyez sur une touche pour lancer les dés\n", id_joueur + 1);
        if (getch())
        {
            joueur_i[id_joueur].position += lancer_de(&de1, &de2);
            if (de1 == de2)
            {
                printf("Vous avez fait double !\n");
            }
            //deplacement_joueur(joueur_i[id_joueur], id_joueur);
            // déplacement du joueur
            /*if (tomber_sur_terrain)
            {
                acheter ou rien;
            }
            else if (tomber_sur_impot)
            {
                payer import
            }
            else if (tomber sur case départ ou stationnement gratuit)
            {
                rien faire ou gagner argent
            }

            */
            nb_lancer++;
        }
    }
    if (nb_lancer == 3)
    {
    // fonction prison
    }

    return joueur_i[id_joueur].argent;
}

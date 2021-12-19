#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structure_joueur/structure_joueur.h"

int tour_joueur(t_joueur joueur_indice[], int id_joueur)
{
    int de1, de2;
    int nb_lancer = 0;
    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || ((de1 == de2)))
    {
        joueur_indice[id_joueur].position += lancer_de(&de1, &de2);
        //deplacement_joueur(tour_joueur_i[id_joueur]);
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
    if (nb_lancer == 3)
    {
        // fonction prison
    }
    return joueur_indice[id_joueur].argent;
}

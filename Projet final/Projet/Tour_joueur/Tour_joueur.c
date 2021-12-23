#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int id_joueur)
{
    int de1, de2;
    int nb_lancer = 0;
    bool case_depart = false;
    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || ((de1 == de2)))
    {
        printf("C'est au joueur %d de jouer ! Appuyez sur ESPACE pour lancer les des\n", id_joueur + 1);
        if (getch() == 32)
        {
            joueur_i[id_joueur].position += lancer_de(&de1, &de2);
            if (joueur_i[id_joueur].position >= 28)
            {
                printf("Vous etes passe par la case depart ! Vous recevez 200");
            }
            joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau

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
            if (de1 == de2)
            {
                printf("Vous avez fait double !\n");
            }
            nb_lancer++;
        }
    }
    if (nb_lancer == 3)
    {
    // fonction prison
    }

    return joueur_i[id_joueur].argent;
}

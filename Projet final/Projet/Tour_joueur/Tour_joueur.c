#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3])
{
    int de1, de2;
    int nb_lancer = 0;
    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || ((de1 == de2)))
    {
        printf("C'est au joueur %d de jouer ! Appuyez sur ESPACE pour lancer les des\n", id_joueur + 1);
        if (getch() == TOUCHE_ESPACE) // On entre 32 en constante, correspondant à ESPACE
        {
            joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les dés
            nb_lancer++; // on augmente le nombre de 1 car les dés ont été lancé
            if (nb_lancer == 3)
            {
            // fonction prison, on interrompt le tour si c'est le troisième double, direct en prison
            }
            if (joueur_i[id_joueur].position >= 28) // on teste si le joueur arrive à la case départ ou non
            {
                printf("Vous etes passe par la case depart ! Vous recevez 200");
                joueur_i[id_joueur].argent += 200;
            }
            joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau

            switch(joueur_i[id_joueur].position)
            {
                case 2:
                    printf("Joueur %d, vous devez payez l'impot sur le revenu s'elevant a 200", id_joueur + 1);
                    joueur_i[id_joueur].argent -= 200;
                    break;

                case 5:
                case 19:
                    printf("chance !\n");
                    break;

                case 12:
                case 26:
                    printf("communaute !\n");
                    break;

                case 21:
                    printf("Allez en prison !\n");
                    break;

                case 14:
                    printf("Vous etes en stationnement gratuit ! Vous pouves soufflez le temps d'un tour !\n");
                    break;

                default:
                    tomber_sur_terrain(joueur_i, nombre_joueurs, id_joueur, cartes_terrain);
                    break;


            }
            /*if (joueur_i[id_joueur].position == 2)
            {
                printf("Joueur %d, vous devez payez l'impot sur le revenu s'elevant a 200", id_joueur + 1);
                joueur_i[id_joueur].argent -= 200;
                break;
            }
            else if (joueur_i[id_joueur].position == 5 || joueur_i[id_joueur].position == 19) /// carte chance
            {
                break;
            }
            else if (joueur_i[id_joueur].position == 12 || joueur_i[id_joueur].position == 26) /// carte communauté
            {
                break;
            }
            else if (joueur_i[id_joueur].position == 14) /// stationnement ou case départ*
            {
                printf("Vous etes en stationnement gratuit ! Vous pouves soufflez le temps d'un tour !\n");
                break;
            }
            else
            {
                tomber_sur_terrain(joueur_i, nombre_joueurs, id_joueur, cartes_terrain);
                break;
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
            if (de1 == de2)
            {
                printf("Vous avez fait double !\n");
            }
        }
    }
    return joueur_i[id_joueur].argent;
}

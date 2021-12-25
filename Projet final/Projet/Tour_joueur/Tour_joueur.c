#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3])
{
    int de1, de2;
    int nb_lancer = 0;
    /// On demande au joueur les autres actions qu'il veut effectuer avant de lancer les dés et commencer le tour
    printf("C'est a %s de jouer !\n"
           "Appuyez sur ESPACE pour lancer les des\n"
           "Appuyez sur 'V' pour vendre des maisons\n"
           "Appuyez sur 'H' pour hypothequer des terrains\n", joueur_i[id_joueur].pseudo);
    switch (getch())
    {
        case TOUCHE_ESPACE:
            while ((nb_lancer == 0) || ((de1 == de2)))
            {
                //printf("C'est au joueur %d de jouer ! Appuyez sur ESPACE pour lancer les des\n", id_joueur + 1);
                //if (getch() == TOUCHE_ESPACE) // On entre 32 en constante, correspondant à ESPACE
                //{
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

                    if (de1 == de2)
                    {
                        printf("Vous avez fait double !\n");
                    }
                }
            }
            return joueur_i[id_joueur].argent;

        case 'h':
        case 'H':
            break;

        case 'v':
        case 'V':
            break;

    }
}


    /// tour d'un joueur, ou autre lancer car dés doubles

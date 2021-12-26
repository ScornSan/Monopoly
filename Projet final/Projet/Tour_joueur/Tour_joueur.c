#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3], int id_carte[])
{
    int de1, de2;
    int nb_lancer = 0;
    int key;
    /// On demande au joueur les autres actions qu'il veut effectuer avant de lancer les dés et commencer le tour

    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || (de1 == de2))
    {
        fflush(stdin);
        if (nb_lancer == 0)
        {
            printf("C'est au joueur %d de jouer ! Appuyez sur ESPACE pour lancer les des\n"
            "Appuyez sur 'h' pour hypothequer une propriete\n"
            "Appuyez sur 'v' pour vendre des maisons / hotels\n", id_joueur + 1);
            key = getch();
        }
        else
        {
            printf("C'est au joueur %d de jouer ! Appuyez sur ESPACE pour lancer les des\n", id_joueur + 1);
            key = getch();
        }

        if (key == TOUCHE_ESPACE) // On entre 32 en constante, correspondant à ESPACE
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
                    tomber_sur_terrain(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte);
                    break;
            }
        }
        else if ((key == 'h' || key == 'H') && nb_lancer == 0)
        {
            printf("Hypotheque !\n");
        }
        else if ((key == 'v' || key == 'V' ) && nb_lancer == 0)
        {
            printf("Vente !\n");
            vente_maisons(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte);
        }
    }
    return joueur_i[id_joueur].argent;
}

    /// tour d'un joueur, ou autre lancer car dés doubles

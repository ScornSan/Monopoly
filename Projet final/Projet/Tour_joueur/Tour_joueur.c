#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3], int id_carte[])
{
    int longueur;
    int longueur_2;
    int de1, de2;
    int nb_lancer = 0;
    int key;
    char chaine[10] = "";
    char phrase_impot[100] = ", vous devez payez l'impot sur le revenu s'elevant a 200";
    char phrase_stationnement[100] = " est en stationnement gratuit et peut souffler pendant un tour !";
    char phrase_prison[100] = ", allez en Prison !";
    char phrase_commu[100] = "Vous etes tombes sur une case communaute!";
    char phrase_commu_2[100] = "Appuyez sur ESPACE pour piocher une carte communaute";
    char phrase_chance[100] = "Vous etes tombes sur une case chance!";
    char phrase_chance_2[100] = "Appuyez sur ESPACE pour piocher une carte chance";
    /// On demande au joueur les autres actions qu'il veut effectuer avant de lancer les d�s et commencer le tour

    /// v�rification tour suivant ou pas
    while ((nb_lancer == 0) || (de1 == de2))
    {
        fflush(stdin);
        if (nb_lancer == 0)
        {
            carre_noir();
            char chaine1[20] = "C'est a ";
            char chaine2[100] = " de jouer ! Appuyez sur ESPACE pour lancer les des";
            char phrase_prop_vente[50] = " Appuyez sur 'v' pour vendre une propriete";
            char phrase_prop_hypotheque[50] = " Appuyez sur 'h' pour hypothequer une propriete";

            longueur = (strlen(chaine1)+ strlen(joueur_i[id_joueur].pseudo) + strlen(chaine2));
            placement_script(longueur, 0);
            printf("%s%s%s\n", chaine1, joueur_i[id_joueur].pseudo, chaine2);

            placement_script(strlen(phrase_prop_vente), 1);
            printf("%s", phrase_prop_vente);

            placement_script(strlen(phrase_prop_hypotheque), 2);
            printf("%s", phrase_prop_hypotheque);
            key = getch();
        }
        else
        {
            carre_noir();
            char chaine[100] = "Vous avez fait double ! A vous de rejouez, ";
            placement_script(strlen(chaine), 0);
            printf("%s%s", chaine, joueur_i[id_joueur].pseudo);
            key = getch();
        }

        if (key == TOUCHE_ESPACE) // On entre 32 en constante, correspondant � ESPACE
        {
            joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les d�s
            //deplacement_pion_graph(de1, de2);
            nb_lancer++; // on augmente le nombre de 1 car les d�s ont �t� lanc�
            if (nb_lancer == 3)
            {
                // fonction prison, on interrompt le tour si c'est le troisi�me double, direct en prison
            }
            if (joueur_i[id_joueur].position >= 28) // on teste si le joueur arrive � la case d�part ou non
            {
                char chaine[100] = "Vous etes passe par la case depart ! Vous recevez 200";
                int longueur = strlen(chaine);
                placement_script(longueur,2);
                printf("%s",chaine);
                joueur_i[id_joueur].argent += 200;
            }
            joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau

            switch(joueur_i[id_joueur].position)
            {
                case 2:

                    longueur = strlen(chaine)+strlen(phrase_impot);
                    placement_script(longueur,2);
                    printf("%s%s", joueur_i[id_joueur].pseudo, phrase_impot);
                    joueur_i[id_joueur].argent -= 200;
                    sleep(3);
                    break;

                //case 5:
                case 19:
                    longueur = strlen(phrase_chance);
                    longueur_2 = strlen(phrase_chance_2);
                    placement_script(longueur,2);
                    printf("%s",phrase_chance);
                    placement_script(longueur_2,3),
                    printf("%s",phrase_chance_2);
                    sleep(3);

                    break;

                //case 12:
                case 26:
                    longueur = strlen(phrase_commu);
                    longueur_2 = strlen(phrase_commu_2);
                    placement_script(longueur,2);
                    printf("%s",phrase_commu);
                    placement_script(longueur_2,3),
                    printf("%s",phrase_commu_2);
                    sleep(3);

                    break;

                case 21:
                    longueur = strlen(phrase_prison) + strlen(joueur_i[id_joueur].pseudo);
                    placement_script(longueur,2);
                    printf("%s%s",joueur_i[id_joueur].pseudo, phrase_prison);
                    sleep(3);

                    break;

                case 14:
                    longueur = strlen(phrase_stationnement) + strlen(joueur_i[id_joueur].pseudo);
                    placement_script(longueur,2);
                    printf("%s%s",joueur_i[id_joueur].pseudo, phrase_stationnement);
                    sleep(3);
                    break;

                default:
                    tomber_sur_terrain(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte);
                    break;
            }
        }
        else if ((key == 'h' || key == 'H') && nb_lancer == 0)
        {
            carre_noir();
            char chaine[100] = " a demande une Hypotheque !";
            int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo) ;
            placement_script(longueur,0);
            printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
            hypothequer(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte);
        }
        else if ((key == 'v' || key == 'V' ) && nb_lancer == 0)
        {
            carre_noir();
            char chaine[100] = " a demande une Vente !";
            int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo);
            placement_script(longueur,0);
            printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
            vente_maisons(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte);
        }
    }
    return joueur_i[id_joueur].argent;
}

    /// tour d'un joueur, ou autre lancer car d�s doubles



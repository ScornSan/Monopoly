#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3], int id_carte[])
{
    int longueur;
    int longueur_2;
    int de1, de2;
    int nb_lancer = 0;
<<<<<<< HEAD
    int nb_tour_prison = 0;
=======
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
    int key;
    char chaine[10] = "";
    char phrase_impot[100] = ", vous devez payez l'impot sur le revenu s'elevant a 200";
    char phrase_stationnement[100] = " est en stationnement gratuit et peut souffler pendant un tour !";
    char phrase_prison[100] = ", allez en Prison !";
<<<<<<< HEAD
    char phrase_commu[100] = "Vous etes tombes sur une case communaute!";
    char phrase_commu_2[100] = "Appuyez sur ENTRER pour piocher une carte communaute";
    char phrase_chance[100] = "Vous etes tombes sur une case chance!";
    char phrase_chance_2[100] = "Appuyez sur ENTRER pour piocher une carte chance";
=======
    char phrase_commu[100] = ", vous etes tombes sur une case communaute!";
    char phrase_commu_2[100] = "Appuyez sur ESPACE pour piocher une carte communaute";
    char phrase_chance[100] = ", vous etes tombes sur une case chance!";
    char phrase_chance_2[100] = "Appuyez sur ESPACE pour piocher une carte chance";
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
    /// On demande au joueur les autres actions qu'il veut effectuer avant de lancer les dés et commencer le tour

    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || (de1 == de2))
    {
        fflush(stdin);
<<<<<<< HEAD

=======
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
        if (nb_lancer == 0)
        {
            carre_noir();
            char chaine1[20] = "C'est a ";
            char chaine2[100] = " de jouer ! Appuyez sur ESPACE pour lancer les des";
            char phrase_prop_vente[50] = " Appuyez sur 'v' pour vendre une propriete";
            char phrase_prop_hypotheque[50] = " Appuyez sur 'h' pour hypothequer une propriete";

            longueur = (strlen(chaine1)+ strlen(joueur_i[id_joueur].pseudo) + strlen(chaine2));
            placement_script(longueur, 0);
<<<<<<< HEAD
            printf("%s%s%s\n", chaine1, joueur_i[id_joueur].pseudo, chaine2);
=======
            printf("%s%s%s", chaine1, joueur_i[id_joueur].pseudo, chaine2);
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a

            placement_script(strlen(phrase_prop_vente), 1);
            printf("%s", phrase_prop_vente);

            placement_script(strlen(phrase_prop_hypotheque), 2);
            printf("%s", phrase_prop_hypotheque);
            key = getch();
        }
        else
        {
            carre_noir();
<<<<<<< HEAD
            char chaine[100] = "Vous avez fait double ! A vous de rejouez, ";
            placement_script(strlen(chaine), 0);
            printf("%s%s", chaine, joueur_i[id_joueur].pseudo);
=======
            char chaine[100] = " ,vous avez fait double ! A vous de rejouez, ";
            longueur = (strlen(chaine) + strlen(joueur_i[id_joueur].pseudo)) ;
            placement_script(longueur, 0);
            printf("%s%s",  joueur_i[id_joueur].pseudo, chaine);
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
            key = getch();
        }

        if (key == TOUCHE_ESPACE) // On entre 32 en constante, correspondant à ESPACE
        {
<<<<<<< HEAD
            joueur_i[id_joueur].ancienne_position = joueur_i[id_joueur].position; //

            joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les dés
            nb_lancer++; // on augmente le nombre de 1 car les dés ont été lancé
            if (nb_lancer == 3 || joueur_i[id_joueur].prison == true)
            {
                joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau

                deplacement_joueur(joueur_i, nombre_joueurs, id_joueur);
                deplacement_joueur(joueur_i[id_joueur], nombre_joueurs, id_joueur);

                if (joueur_i[id_joueur].prison == true)
                {
                    nb_tour_prison++;
                    case_prison(joueur_i, nombre_joueurs, id_joueur, de1, de2, nb_tour_prison); // la fonction s'active s'il passe son tour en prison
                    break;
                }
                else // si c'est la premiere fois qu'il arrive en prison
                {
                    placement_script(strlen(phrase_prison), 0);
=======
            joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les dés
            //deplacement_pion_graph(de1, de2);
            nb_lancer++; // on augmente le nombre de 1 car les dés ont été lancé
            if (nb_lancer == 3 || joueur_i[id_joueur].prison == true)
            {
                if (joueur_i[id_joueur].prison == true)
                {
                    char chaine[100] = ", vous etes deja en prison";
                    int longueur = (strlen(joueur_i[id_joueur].pseudo)+ strlen(chaine));
                    placement_script(longueur, 0);
                    printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
                    case_prison(joueur_i, nombre_joueurs, id_joueur, de1, de2); // la fonction s'active s'il est deja en prison
                    break;
                }

                else // si c'est la premiere fois qu'il arrive en prison
                {
                    int longueur = (strlen(phrase_prison)+ strlen(joueur_i[id_joueur].pseudo));
                    placement_script(longueur, 0);
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
                    printf("%s%s", joueur_i[id_joueur].pseudo, phrase_prison);
                    usleep(50000);
                    joueur_i[id_joueur].prison = true;
                    break;
                }
            }
            else if (nb_lancer < 3 && joueur_i[id_joueur].prison == false)
            {
                if (joueur_i[id_joueur].position >= 28) // on teste si le joueur arrive à la case départ ou non
                {
<<<<<<< HEAD
                    placement_script(strlen(phrase_impot), 2);
                    printf("%s%s",chaine);
                    joueur_i[id_joueur].argent += 200;
                }
                joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau
                printf("%d", joueur_i[id_joueur].ancienne_position);
                printf("%d", joueur_i[id_joueur].position);
                deplacement_joueur(joueur_i, nombre_joueurs, id_joueur); //
=======
                    char chaine[100] = ", vous etes passe par la case depart ! Vous recevez 200";
                    int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo);
                    placement_script(longueur,2);
                    printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
                    joueur_i[id_joueur].argent += 200;
                }
                joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a

                switch(joueur_i[id_joueur].position)
                {
                    case 2:
<<<<<<< HEAD
                        longueur = strlen(chaine)+strlen(phrase_impot);
=======

                        longueur = strlen(joueur_i[id_joueur].pseudo)+strlen(phrase_impot);
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
                        placement_script(longueur,2);
                        printf("%s%s", joueur_i[id_joueur].pseudo, phrase_impot);
                        joueur_i[id_joueur].argent -= 200;
                        usleep(3000);
                        break;

                    //case 5:
                    case 19:
<<<<<<< HEAD
                        longueur = strlen(phrase_chance);
                        longueur_2 = strlen(phrase_chance_2);
                        placement_script(longueur,2);
                        printf("%s",phrase_chance);
=======
                        longueur = strlen(phrase_chance) + strlen(joueur_i[id_joueur].pseudo);
                        longueur_2 = strlen(phrase_chance_2);
                        placement_script(longueur,2);
                        printf("%s%s",joueur_i[id_joueur].pseudo, phrase_chance);
>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
                        placement_script(longueur_2,3),
                        printf("%s",phrase_chance_2);
                        usleep(3000);

                        break;

                    //case 12:
                    case 26:
                        longueur = strlen(phrase_commu);
                        longueur_2 = strlen(phrase_commu_2);
                        placement_script(longueur,2);
                        printf("%s",phrase_commu);
                        placement_script(longueur_2,3),
                        printf("%s",phrase_commu_2);
                        usleep(3000);
<<<<<<< HEAD
=======

>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
                        break;

                    case 21:
                        longueur = strlen(phrase_prison) + strlen(joueur_i[id_joueur].pseudo);
                        placement_script(longueur,2);
                        printf("%s%s",joueur_i[id_joueur].pseudo, phrase_prison);
                        usleep(3000);
<<<<<<< HEAD
=======

>>>>>>> 6191a5483b0435544ebd5616aaa3c556a4710a3a
                        break;

                    case 14:
                        longueur = strlen(phrase_stationnement) + strlen(joueur_i[id_joueur].pseudo);
                        placement_script(longueur,2);
                        printf("%s%s",joueur_i[id_joueur].pseudo, phrase_stationnement);
                        usleep(3000);
                        break;

                    default:
                        tomber_sur_terrain(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte);
                        break;
                }
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

    /// tour d'un joueur, ou autre lancer car dés doubles



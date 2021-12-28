#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3], int id_carte[])
{
    int de1, de2;
    int nb_lancer = 0;
    int key;
    int nb_tour_prison = 0;
    char chaine[10] = "";
    char phrase_impot[100] = ", vous devez payez l'impot sur le revenu s'elevant a 200";
    char phrase_stationnement[100] = "Vous etes en stationnement gratuit ! Vous pouvez pendant un tour !";
    /// On demande au joueur les autres actions qu'il veut effectuer avant de lancer les dés et commencer le tour

    /// vérification tour suivant ou pas
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

        if (key == TOUCHE_ESPACE) // On entre 32 en constante, correspondant à ESPACE
        {
            joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les dés
            //deplacement_pion_graph(de1, de2);
            nb_lancer++; // on augmente le nombre de 1 car les dés ont été lancé
            printf("%d", nb_lancer);
            if (nb_lancer == 3 || joueur_i[id_joueur].prison == true)
            {
                nb_tour_prison++;
                printf("Vous etes en prison ! C'est votre %d tour.", nb_tour_prison);
                joueur[id_joueur].prison = true;
                case_prison(joueur_i, nombre_joueurs, id_joueur, &de1, &de2); // on interrompt le tour si c'est le troisième double, direct en prison
            }
            else
            {
                joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les dés
            }

            if (joueur_i[id_joueur].position >= 28) // on teste si le joueur arrive à la case départ ou non
            {
                char chaine[100] = "Vous etes passe par la case depart ! Vous recevez 200\n";
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
                    longueur = strlen(phrase_stationnement);
                    placement_script(longueur,2);
                    printf("%s", phrase_stationnement);
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



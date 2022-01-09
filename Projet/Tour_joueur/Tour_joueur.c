#include "../Fonctions_actions_joueurs/actions.h"
#include "../Structures/structure_joueur.h"

int tour_joueur(int repere[], t_joueur joueur_i[], int nombre_joueurs, int id_joueur, t_carte cartes_terrain[][3], int id_carte[], int tab_cartes_c[], int loto, int card_chance, int card_commu, int sauvegarde_position[], int banque_de_carte[], int tour_prison[])
{
    int longueur;
    int longueur_2;
    int de1, de2;
    int nb_lancer = 0;
    int key;
    int key_h;
    char chaine[2] = "";
    char phrase_impot[100] = ", vous devez payez l'impot sur le revenu s'elevant a 200";
    char phrase_stationnement[100] = " est en stationnement gratuit et peut souffler pendant un tour !";
    char phrase_prison[50] = ", allez en Prison !";
    char phrase_commu[70] = ", vous etes tombes sur une case communaute!";
    char phrase_commu_2[70] = "Appuyez sur ESPACE pour piocher une carte communaute";
    char phrase_chance[70] = ", vous etes tombes sur une case chance!";
    char phrase_chance_2[70] = "Appuyez sur ESPACE pour piocher une carte chance";
    /// On demande au joueur les autres actions qu'il veut effectuer avant de lancer les d�s et commencer le tour

    /// v�rification tour suivant ou pas
    while ((nb_lancer == 0) || (de1 == de2))
    {
        affichage_argent_joueurs(joueur_i,id_joueur);
        fflush(stdin);
        if (nb_lancer == 0)
        {
            carre_noir();
            char chaine1[20] = "C'est a ";
            char chaine2[100] = " de jouer ! Appuyez sur ESPACE pour lancer les des";
            char phrase_prop_vente[50] = " Appuyez sur 'v' pour vendre une propriete";
            char phrase_prop_hypotheque[80] = " Appuyez sur 'h' pour hypothequer ou racheter une propriete";

            longueur = (strlen(chaine1)+ strlen(joueur_i[id_joueur].pseudo) + strlen(chaine2));
            placement_script(longueur, 0);
            printf("%s%s%s", chaine1, joueur_i[id_joueur].pseudo, chaine2);

            placement_script(strlen(phrase_prop_vente), 1);
            printf("%s", phrase_prop_vente);

            placement_script(strlen(phrase_prop_hypotheque), 2);
            printf("%s", phrase_prop_hypotheque);
            ///affichage_carte(35, 125,cartes_terrain,);
            key = getch();
        }
        else
        {
            carre_noir();
            char chaine[100] = " ,vous avez fait double ! A vous de rejouez, ";
            longueur = (strlen(chaine) + strlen(joueur_i[id_joueur].pseudo)) ;
            placement_script(longueur, 0);
            printf("%s%s",  joueur_i[id_joueur].pseudo, chaine);
            key = getch();
        }
        if (key == TOUCHE_ESPACE) // On entre 32 en constante, correspondant � ESPACE
        {
            nb_lancer++; // on augmente le nombre de 1 car les d�s ont �t� lanc�
            if (nb_lancer == 3 || joueur_i[id_joueur].prison == true)
            {
                tour_prison[id_joueur]++;
                if (joueur_i[id_joueur].prison == true)
                {
                    carre_noir();
                    char chaine[100] = ", vous etes deja en prison";
                    int longueur = (strlen(joueur_i[id_joueur].pseudo)+ strlen(chaine));
                    placement_script(longueur, 0);
                    printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
                    printf(" %d", tour_prison[id_joueur]);
                    sleep(1);
                    case_prison(joueur_i, nombre_joueurs, id_joueur, de1, de2, tour_prison); // la fonction s'active s'il est deja en prison
                    break;
                }

                else // si c'est la premiere fois qu'il arrive en prison
                {
                    joueur_i[id_joueur].prison = true;
                    affichage_pion_prison(id_joueur,joueur_i[id_joueur].prison);
                    remplacement_position(sauvegarde_position,joueur_i[id_joueur].position);
                    joueur_i[id_joueur].ancienne_position = 7;
                    joueur_i[id_joueur].position = 7;
                    carre_noir();
                    int longueur = (strlen(phrase_prison)+ strlen(joueur_i[id_joueur].pseudo));
                    Color(id_joueur + 9, 0);
                    placement_script(longueur, 0);
                    printf("%s%s", joueur_i[id_joueur].pseudo, phrase_prison);
                    usleep(500000);
                    break;
                }
            }
            else if (nb_lancer < 3 && joueur_i[id_joueur].prison == false)
            {
                affichage_pion_prison(id_joueur, joueur_i[id_joueur].prison);
                joueur_i[id_joueur].ancienne_position = joueur_i[id_joueur].position;
                joueur_i[id_joueur].position += lancer_de(&de1, &de2); // on lance les d�s
                deplacement_joueur(joueur_i, nombre_joueurs, id_joueur);
                connaissance_position_curseur(sauvegarde_position);
                if (joueur_i[id_joueur].position >= 28) // on teste si le joueur arrive � la case d�part ou non
                {
                    char chaine[100] = ", vous etes passe par la case depart ! Vous recevez 200";
                    int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo);
                    placement_script(longueur,1);
                    printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
                    joueur_i[id_joueur].argent += 200;
                }
                joueur_i[id_joueur].position = joueur_i[id_joueur].position % 28; // modulo 28, pour faire un tour du plateau
                switch(joueur_i[id_joueur].position)
                {
                case 2:
                    longueur = strlen(joueur_i[id_joueur].pseudo)+strlen(phrase_impot);
                    placement_script(longueur,2);
                    printf("%s%s", joueur_i[id_joueur].pseudo, phrase_impot);
                    joueur_i[id_joueur].argent -= 200;
                    usleep(3000);
                    break;

                case 5:
                case 19:
                    longueur = strlen(phrase_chance) + strlen(joueur_i[id_joueur].pseudo);
                    longueur_2 = strlen(phrase_chance_2);
                    placement_script(longueur,2);
                    printf("%s%s",joueur_i[id_joueur].pseudo, phrase_chance);
                    placement_script(longueur_2,3),
                                     printf("%s",phrase_chance_2);
                    usleep(3000);

                    break;

                case 12:
                case 26:
                    longueur = strlen(phrase_commu);
                    longueur_2 = strlen(phrase_commu_2);
                    placement_script(longueur,2);
                    printf("%s",phrase_commu);
                    placement_script(longueur_2,3),
                                     printf("%s",phrase_commu_2);
                    usleep(3000);

                    break;

                case 21:
                    carre_noir();
                    longueur = strlen(phrase_prison) + strlen(joueur_i[id_joueur].pseudo);
                    placement_script(longueur,2);
                    printf("%s%s",joueur_i[id_joueur].pseudo, phrase_prison);
                    joueur_i[id_joueur].prison = true;
                    affichage_pion_prison(id_joueur,joueur_i[id_joueur].prison);
                    remplacement_position(sauvegarde_position,joueur_i[id_joueur].position);
                    joueur_i[id_joueur].ancienne_position = 7;
                    joueur_i[id_joueur].position = 7;
                    usleep(300000);
                    break;

                case 14:
                    longueur = strlen(phrase_stationnement) + strlen(joueur_i[id_joueur].pseudo);
                    placement_script(longueur,2);
                    printf("%s%s",joueur_i[id_joueur].pseudo, phrase_stationnement);
                    usleep(3000);
                    break;

                default:
                    tomber_sur_terrain(repere, joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte, banque_de_carte);
                    break;
                }
            }
        }
        else if ((key == 'h' || key == 'H') && nb_lancer == 0)
        {
            gotoligcol(60, 60);
            printf("%d", id_carte[id_joueur]);
            if (id_carte[id_joueur] - 1 != 0)
            {
                carre_noir();
                char chaine[100] = " a demande une hypotheque / rachat !";
                int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo) ;
                placement_script(longueur,0);
                printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
                char chaine_rachat_hypo[75] = "Appuyez sur 'R' pour racheter ou sur 'H' pour hypothequer une propriete !";
                longueur = strlen(chaine_rachat_hypo) ;
                placement_script(longueur,1);
                printf("%s", chaine_rachat_hypo);
                key_h = getch();
                if ((key_h == 'r' || key_h == 'R'))
                {
                    gotoligcol(60, 60);
                    printf("%d", id_carte[id_joueur]);
                    rachat_terrain(joueur_i, id_joueur, cartes_terrain, id_carte, banque_de_carte, repere);
                }
                else if(key_h == 'h' || key_h == 'H')
                {
                    hypothequer(joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte, repere, banque_de_carte);
                }
            }
            else
            {
                carre_noir();
                char chaine[100] = ", vous ne possedez aucun terrain !";
                int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo) ;
                placement_script(longueur,0);
                printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
                sleep(1);
            }
        }
        else if ((key == 'v' || key == 'V' ) && nb_lancer == 0)
        {
            carre_noir();
            char chaine[100] = " a demande une Vente !";
            int longueur = strlen(chaine) + strlen(joueur_i[id_joueur].pseudo);
            placement_script(longueur,0);
            printf("%s%s",joueur_i[id_joueur].pseudo, chaine);
            vente_maisons(repere, joueur_i, nombre_joueurs, id_joueur, cartes_terrain, id_carte, banque_de_carte);
        }
        else if ((key == 'm' || key == 'M' ) && nb_lancer == 0)
        {
            echap();
        }
    }
    return joueur_i[id_joueur].argent;
}

/// tour d'un joueur, ou autre lancer car d�s doubles



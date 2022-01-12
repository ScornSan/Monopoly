#include "../Structures/structure_joueur.h"
#include "../Fonctions_actions_joueurs/actions.h"
#include "../Affichage_plateau/affichage_plateau.h"

void faillite(t_joueur joueur[], int id_joueur, int nombre_de_joueurs, t_carte terrain[][3], int identifiant_max[], int dette, int banque_de_carte[], int repere[], bool elimination[])
{
    char phrase_prop_vente[50] = " Appuyez sur 'v' pour vendre une propriete";
    char phrase_prop_hypotheque[50] = " Appuyez sur 'h' pour hypothequer une propriete";
    int key;
    int nb_cartes;
    if (identifiant_max[id_joueur] ==  1) // il n'a pas de terrain acheté, faillite car plus d'argent
    {
        carre_noir();
        char pas_de_terrain[60] = ", vous ne possedez aucun bien";
        char faillite[50] = "Vous avez fait faillite, ";
        char perdu[50] = "Vous avez perdu la partie !";
        placement_script(strlen(pas_de_terrain), 0);
        printf("%s%s", joueur[id_joueur], pas_de_terrain);
        placement_script(strlen(faillite), 2);
        printf("%s%s", faillite, joueur[id_joueur]);
        placement_script(strlen(perdu), 4);
        printf("%s", perdu);
        sleep(2);
        elimination[id_joueur] = true;
    }
    else if (joueur[id_joueur].argent < dette)
    {
        for (int i = 0; i < GROUPES_CARTES; i++)
        {
            if (i % 2 == 0 || i == 1)
            {
                nb_cartes = 2;
            }
            else
            {
                nb_cartes = 3;
            }
            for (int j = 0; j < nb_cartes; j++)
            {
                key = getch();
                while (joueur[id_joueur].argent < dette && terrain[i][j].possession_carte == id_joueur)
                {
                    if (key == 'h' || key == 'H')
                    {
                        carre_noir();
                        char chaine[100] = " a demande une Hypotheque !";
                        int longueur = strlen(chaine) + strlen(joueur[id_joueur].pseudo) ;
                        placement_script(longueur,0);
                        printf("%s%s",joueur[id_joueur].pseudo, chaine);
                        hypothequer(joueur, nombre_de_joueurs, id_joueur, terrain, identifiant_max, repere);
                    }

                    if (key == 'v' || key == 'V')
                    {
                        carre_noir();
                        char chaine[100] = " a demande une Vente !";
                        int longueur = strlen(chaine) + strlen(joueur[id_joueur].pseudo);
                        placement_script(longueur,0);
                        printf("%s%s",joueur[id_joueur].pseudo, chaine);
                        vente_maisons(repere, joueur, nombre_de_joueurs, id_joueur, terrain, identifiant_max, banque_de_carte);
                    }
                }
            }
        }
    }
}



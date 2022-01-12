#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void partie_en_cours(int pouvoirsauv, int nombre_de_joueurs, t_joueur joueur_x[], t_carte cartes[][3], int id_max_cartes[])
{
    int repere[4]; // tableau qui configure les lignes, colonnes, couleur texte et couleur du fond
    int tab_c[12]; // tzbleau de cartes chances et communauté
    t_carte tab[GROUPES_CARTES][3]; // initialisation structures de cartes de proprietes
    int fin_de_partie;
    pouvoirsauv = 1;
    int banque_de_carte[2];
    banque_de_carte[0] = 32;
    banque_de_carte[1] = 12;
    int i, j, nb_cartes;
    int sauvegarde_position[2];
    nombre_de_joueurs = demander_nb_joueur();
    int card_chance = 0; // va venir piocher la premiere carte chance
    int card_commu = 0; // va venir piocher la premiere carte commmu
    t_joueur joueur[nombre_de_joueurs]; // on crée un tableau de structures de joueurs, de taille du nombre demand�
    creation_joueurs(joueur, nombre_de_joueurs, id_max_cartes); // on cr�e les structures joueurs
    remplissages_cartes(tab); // on remplit les cartes terrains
    remplissage_chance_commu(tab_c, 12); // on remplit les cartes chance et commu
    //melangeurCarte(tab_c, 16);
    int tour_prison[nombre_de_joueurs];
    tour_prison[0] = 0;
    tour_prison[1] = 0;
    tour_prison[2] = 0;
    tour_prison[3] = 0;
    affichage_plateau();
    affichage_prix_terrain(repere, tab);
    affichage_pseudo_joueurs(nombre_de_joueurs, joueur);
    affichage_nom_terrain(repere, tab);
    int loto = 0;
    bool elimination[nombre_de_joueurs];
    for (int a = 0; a < nombre_de_joueurs; a++)
    {
        elimination[a] = false;
    }

    while (nombre_de_joueurs != 1)
    {
        for (int id = 0; id < nombre_de_joueurs; id++)
        {
            if (elimination[id] == false)
            {
                tour_joueur(repere, joueur, nombre_de_joueurs, id, tab, id_max_cartes, tab_c, loto, card_chance, card_commu, sauvegarde_position, banque_de_carte, tour_prison, elimination);
            }
            else
            {
                printf("%s est elimine", joueur[id].pseudo);
                continue; // on sort de la boucle et on fait la fin du jeu
            }
        }
    }
    printf("fin de jeu");
    //deplacement_joueur();*/
}

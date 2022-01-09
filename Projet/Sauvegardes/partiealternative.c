#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

// Ce sousprog se lance après le lancement d'une charge de partie !

void partiealternative(int nombre_de_joueurs, t_joueur joueur[], t_carte cartes)
{
    int repere[4]; // tableau qui configure les lignes, colonnes, couleur texte et couleur du fond
    int tab_c[16]; // tzbleau de cartes chances et communauté
    t_carte tab[GROUPES_CARTES][3]; // initialisation structures de cartes de proprietes
    int fin_de_partie;

    int banque_de_carte[2];
    banque_de_carte[0] = 32;
    banque_de_carte[1] = 12;

    int sauvegarde_position[2];
    int identifiant_carte[nombre_de_joueurs];
    int card_chance = 0; // va venir piocher la premiere carte chance
    int card_commu = 0; // va venir piocher la premiere carte commmu
    remplissages_cartes(tab); // on remplit les cartes terrains
    remplissage_chance_commu(tab_c);
    melangeurCarte(tab_c);
    int tour_prison[nombre_de_joueurs];
    tour_prison[0] = 0;
    tour_prison[1] = 0;
    tour_prison[2] = 0;
    tour_prison[3] = 0;
    affichage_plateau();
    affichage_pseudo_joueurs(nombre_de_joueurs, joueur);
    int loto = 0;

    while (nombre_de_joueurs != 1)
    {
        for (int i = 0; i < nombre_de_joueurs; i++)
        {
            fin_de_partie = tour_joueur(repere, joueur, nombre_de_joueurs, i, tab, identifiant_carte, tab_c, loto, card_chance, card_commu, sauvegarde_position, banque_de_carte, tour_prison);
            if (fin_de_partie < 0)
            {
                printf("%s est elimine", joueur[i].pseudo);
                break; // on sort de la boucle et on fait la fin du jeu
            }
        }
    }
    printf("fin de jeu");

}

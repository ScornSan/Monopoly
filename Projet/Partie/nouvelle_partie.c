#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"


void partie_en_cours(int repere[4])
{
    t_carte tab[GROUPES_CARTES][3];
    int fin_de_partie;
    int loto = 0;
    int card_chance = 0;
    int card_commu = 0;
    srand(time(NULL));
    int tailletabcartes = 16;
    int tabcarteschance[tailletabcartes];
    int tabcartescommu[tailletabcartes];
    int nombre_de_joueurs = demander_nb_joueur();
    int identifiant_carte[nombre_de_joueurs];
    remplissage(tabcarteschance, tailletabcartes);
    remplissage(tabcartescommu, tailletabcartes);
    tab_cartes_c(tabcarteschance, tailletabcartes);
    tab_cartes_c(tabcartescommu, tailletabcartes);
    t_joueur joueur[nombre_de_joueurs]; // on crée un tableau de structures de joueurs, de taille du nombre demandé
    creation_joueurs(joueur, nombre_de_joueurs, identifiant_carte); // on crée les structures joueurs
    remplissages_cartes(tab); // on remplit les cartes terrains
    affichage_plateau();
    affichage_pseudo_joueurs(nombre_de_joueurs,joueur);
    for (int i = 0; i < nombre_de_joueurs; i++)
    {
        affichage_argent_joueurs(joueur, i);
    }

    while (nombre_de_joueurs != 1)
    {
        for (int i = 0; i < nombre_de_joueurs; i++)
        {
            fin_de_partie = tour_joueur(repere, joueur, nombre_de_joueurs, i, tab, identifiant_carte, loto, tabcarteschance, tabcartescommu, card_chance, card_commu);
            if (fin_de_partie < 0)
            {
                break; // on sort de la boucle et on fait la fin du jeu
            }
        }
    }
    printf("fin de jeu");
    //deplacement_joueur();*/
}

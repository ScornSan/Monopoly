#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void partie_en_cours(int repere[4])
{
    t_carte tab[GROUPES_CARTES][3];
    int fin_de_partie;
    int nombre_de_joueurs = demander_nb_joueur();
    int identifiant_carte[nombre_de_joueurs];
    t_joueur joueur[nombre_de_joueurs]; // on crée un tableau de structures de joueurs, de taille du nombre demandé
    creation_joueurs(joueur, nombre_de_joueurs, identifiant_carte); // on crée les structures joueurs
    remplissages_cartes(tab); // on remplit les cartes terrains
    affichage_plateau();
    while (nombre_de_joueurs != 1)
    {
        for (int i = 0; i < nombre_de_joueurs; i++)
        {
            fin_de_partie = tour_joueur(repere, joueur, nombre_de_joueurs, i, tab, identifiant_carte);

            if (fin_de_partie < 0)
            {
                break; // on sort de la boucle et on fait la fin du jeu
            }
        }
    }
    printf("fin de jeu");
    //deplacement_joueur();*/
}

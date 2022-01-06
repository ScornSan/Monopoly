#include "bibli1.h"
#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void tab_cartes_c(int tab[],int taille)
{
    int i = 0; // On initialise un compteur
    int nbcompt = 0; // On initalise un nombre temporaire
    nbcompt = taille; // On attribue la valeur de nb à nbcompt
    for(i=0;i<taille;i++) /// Boucle FOR pour parcourir le tableau
    {
        int tmp; // On initalise un entier temporaire
        int aleatoire = rand()%nbcompt; // l'aléatoire est égal à un nombre aléatoire de 0 à nbcompt (16)
        tmp = tab[aleatoire]; // tmp prend la valeur du tableau en position aléatoire
        tab[aleatoire] = tab[nbcompt-1]; // le tableau indice aléatoire est égal au tableau indice nbcompt-1 (15)
        tab[taille-i-1] = tmp; // le tableau indice taille-i-1 (15 - i) est égal au temp
        nbcompt--; // On retire 1 (MEMOIRE)
    }
}

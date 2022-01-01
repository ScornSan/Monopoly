#include "bibli1.h"

void melangeurCarte(int tab[],int taille)
{
    int i; // On initialise un compteur
    int nbcompt; // On initalise un nombre temporaire
    nbcompt = taille; // On attribue la valeur de nb � nbcompt
    for(i=0;i<taille;i++) /// Boucle FOR pour parcourir le tableau
    {
        int tmp; // On initalise un entier temporaire
        int aleatoire = rand()%nbcompt; // l'al�atoire est �gal � un nombre al�atoire de 0 � nbcompt (16)
        tmp = tab[aleatoire]; // tmp prend la valeur du tableau en position al�atoire
        tab[aleatoire] = tab[nbcompt-1]; // le tableau indice al�atoire est �gal au tableau indice nbcompt-1 (15)
        tab[taille-i-1] = tmp; // le tableau indice taille-i-1 (15 - i) est �gal au temp
        nbcompt--; // On retire 1 (MEMOIRE)
    }
}

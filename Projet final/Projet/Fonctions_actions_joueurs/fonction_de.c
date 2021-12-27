#include "actions.h"
#include "../Structures/structure_joueur.h"


int lancer_de(int* val_de1, int* val_de2)
{
    // variables
    long int somme_de;
    srand(time(NULL)); // initialisation g�n�rateur de nombres
    // On demande de lancer les d�s

    // g�n�ration de deux d�s
    *val_de1 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    *val_de2 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    somme_de = *val_de1 + *val_de2;
    char chaine[20] = "Vous avez fait ";
    char chaine2[50] = " ! Avancez de ";
    longueur = strlen(chaine) + strlen(chaine2) + 12;
    placement_script(longueur,2);
    printf("%s%d et %d%s%d cases !",chaine, *val_de1, *val_de2, chaine2,*val_de1 + *val_de2);
    sleep(3);
    return somme_de;
}


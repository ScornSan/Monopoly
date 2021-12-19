#include "actions.h"

int lancer_de(int* val_de1, int* val_de2)
{
    // variables
    long int somme_de;
    srand(time(NULL)); // initialisation générateur de nombres
    // On demande de lancer les dés

    // génération de deux dés
    *val_de1 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    *val_de2 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    somme_de = *val_de1 + *val_de2;
    printf("Vous avez fait %d et %d ! Avancez de %d cases\n", *val_de1, *val_de2, *val_de1 + *val_de2);
    return somme_de;
}


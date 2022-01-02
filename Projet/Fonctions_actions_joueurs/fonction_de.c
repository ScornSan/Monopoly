#include "actions.h"

int lancer_de(int* val_de1, int* val_de2)
{
    // variables
    int somme_de;
    char chaine_de1[20] = "Vous avez fait";
    char chaine_de2[20] = "et";
    char chaine_de3[20] = "! Avancez de";
    char chaine_de4[20] = "cases\n";
    srand(time(NULL)); // initialisation générateur de nombres
    // On demande de lancer les dés

    // génération de deux dés
    *val_de1 = 5;//(rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    *val_de2 = 3;//(rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    somme_de = *val_de1 + *val_de2;
    carre_noir();
    longueur = (strlen(chaine_de1) + strlen(chaine_de2) + strlen(chaine_de3) + strlen(chaine_de4));
    placement_script(longueur, 0);
    printf("%s %d %s %d %s %d %s", chaine_de1, *val_de1, chaine_de2, *val_de2, chaine_de3, *val_de1 + *val_de2, chaine_de4);
    return somme_de;
}


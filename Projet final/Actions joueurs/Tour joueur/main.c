#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_DE 6
#define MIN_DE 1

void lancer_de(int* val_de1, int* val_de2)
{
    // variables
    srand(time(NULL)); // initialisation générateur de nombres
    // On demande de lancer les dés

    // génération de deux dés
    *val_de1 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    *val_de2 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    printf("Vous avez fait %d et %d ! Avancez de %d cases\n", *val_de1, *val_de2, *val_de1 + *val_de2);
}

int tour_joueur_x()
{
    int de1 = 0, de2 = 0;
    int nb_lancer = 0;
    int argent = 500;
    /// vérification tour suivant ou pas
    while ((nb_lancer == 0) || ((de1 == de2)))
    {

        lancer_de(&de1, &de2);
        // déplacement du joueur
        /*if (tomber_sur_terrain)
        {
            acheter ou rien;
        }
        else if (tomber_sur_impot)
        {
            payer import
        }
        else if (tomber sur case départ ou stationnement gratuit)
        {
            rien faire ou gagner argent
        }

        */
        nb_lancer++;
        printf("Fin de boucle %d%d\n", de1, de2);
    }
    if (nb_lancer == 3)
    {
        printf("T'es en prison mec\n");
        // fonction prison
    }
    return argent;
}

int main()
{
    //while (1 != 0)
    //{
    int a = tour_joueur_x();
    printf("%d", a);
    //sleep(1);
    //}

    return 0;
}

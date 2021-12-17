#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DE 6
#define MIN_DE 1

int aller_en_prison()
{
    int compteur_prison = 0;
    printf("On a fait un double\n");
    compteur_prison++;
    if (compteur_prison == 3)
    {
        printf("prison");
        compteur_prison = 0;
        // appelle de la fonction prison
    }

    return 0;
}

int fct_de()
{
    // variables
    int val_de1 = 0;
    int val_de2 =  0;
    int compteur_prison = 0;
    srand(time(NULL)); // initialisation générateur de nombres

    // génération de deux dés
    val_de1 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    val_de2 = (rand() % (MAX_DE-MIN_DE + 1) + MIN_DE);
    printf("%d\n%d\n", val_de1, val_de2);
    if (val_de1 == val_de2)
    {
        aller_en_prison();
    }
    return val_de1 + val_de2;
}

int main()
{
    int a = 0;
    a = fct_de();
    printf("%d", a);
    return 0;
}

#include "bibli1.h"

void pioche(int tab[])
{
    // Le syst�me de pioche est simple, on pioche la premi�re carte a chaque fois donc tab[0]
    // Puis on d�cale tout et on remet le tab[0] en position 15

    int carte = tab[0];
    int temp = tab[0];
    for (int i=0; i<TAILLE_CARTES-1; i++)
    {
        tab[i] = tab[i+1];
    }
    tab[15] = temp;
}

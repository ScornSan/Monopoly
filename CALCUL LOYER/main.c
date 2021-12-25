#include <stdio.h>
#include <stdlib.h>
#define QUARTIERS 8


typedef struct carte
{
    int puissance_carte;
    int nb_maison;
    int prix_achat;
    int prix_loyer;
    int prix_vente;
    int prix_rachat;

}t_carte;

void remplissage_carte (t_carte carte[][3]/*, t_carte carte*/)
{

    int nbCarte;
    int nbDeMaison; // nb correspondra en fait à nb_maison de la structure de carte
    printf("nb de maison :\n");
    scanf("%d", &nbDeMaison);
    for (int i = 0; i < QUARTIERS; i++)
    {
        printf("Quartier %d\n", i+1);
        if ( i % 2 == 0 || i == 1)
        {
            nbCarte = 2;
        }
        else
        {
            nbCarte = 3;
        }

        for (int j = 0; j < nbCarte; j++)
        {
            carte[i][j].prix_achat = (j * 10) + (i * 20) + 20;
           // carte[i][j].prix_loyer =  carte[i][j].prix_achat * 11 + 20;
            switch(nbDeMaison)
            {
                case 1 : carte[i][j].prix_loyer =  carte[i][j].prix_achat * 2;
                         break;
                case 2 : carte[i][j].prix_loyer =  carte[i][j].prix_achat * 3;
                         break;
                case 3 : carte[i][j].prix_loyer =  carte[i][j].prix_achat * 4;
                         break;
                case 4 : carte[i][j].prix_loyer =  carte[i][j].prix_achat * 5;
                         break;
                case 5 : carte[i][j].prix_loyer =  carte[i][j].prix_achat * 11 + 20;
                         break;
            }

           printf("%d$ \t ", carte[i][j].prix_loyer );
        }
         putchar('\n');
    }
}

int main()
{
   t_carte tab[8][3];
   t_carte carte;
  // remplissage_structure(carte);
   remplissage_carte(tab);
  // affichage_carte(tab);

}

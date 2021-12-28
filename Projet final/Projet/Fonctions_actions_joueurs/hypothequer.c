#include "../Structures/structure_joueur.h"
/// HYPOTEQUER UNE MAISON :

void hypothequer (t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[])
{
    int touche = 25; // un joueur ne pourra jamais avoir 25 propriete, donc jamais un identifiant de 25
    int fleche2;
    int nb_cartes;

    while (touche > identifiant_joueur_max[id_joueur] ) // On entre dans le blindage
    {
        printf("%s, quelle propriete voulez vous hypotequer ?", pion_joueur[id_joueur].pseudo);
        printf("l'id max est de %d : \t", identifiant_joueur_max[id_joueur]);
        fflush(stdin);
        scanf("%d", &touche);
    }

    while (touche <= identifiant_joueur_max[id_joueur] )
    {
        for (int i = 0; i < GROUPES_CARTES; i++)
        {
            if (i % 2 == 0 || i == 1)
            {
                nb_cartes = 2;
            }
            else
            {
                nb_cartes = 3;
            }
            for (int j = 0; j < nb_cartes; j++)
            {
                if ( touche == terrain[i][j].id_carte && terrain[i][j].hypotheque == false)
                {
                    while ( terrain[i][j].nb_maison >= 1 )
                    {
                        terrain[i][j].nb_maison--;
                        pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + (terrain[i][j].prix_maison/2);
                    }

                    printf("Vous recuperer l'argent de la valeur de l'hypoteque de votre propriete hypotequee");
                    printf("Vous ne pouvez plus percevoir le loyer de cette propriete");
                    pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + terrain[i][j].val_hypotheque;
                    terrain[i][j].hypotheque ==  true;
                }
            }
            break;
            }
        break;
        }
    }

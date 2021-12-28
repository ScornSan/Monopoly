#include "../Structures/structure_joueur.h"
/// HYPOTEQUER UNE MAISON :

void hypothequer (t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[])
{
    int touche = 25; // un joueur ne pourra jamais avoir 25 propriete, donc jamais un identifiant de 25
    int fleche2;
    int nb_cartes;
    while (touche > identifiant_joueur_max[id_joueur] ) // On entre dans le blindage
    {
        char phrase_prop_hypotheque[100] = ", quelle propriete voulez vous hypotequer ?";
        longueur = strlen(phrase_prop_hypotheque) + strlen(pion_joueur[id_joueur].pseudo);
        placement_script(longueur,2);
        printf("%s%s", phrase_prop_hypotheque, pion_joueur[id_joueur].pseudo);
        placement_script(19,3);
        printf("l id max est de %d : ", identifiant_joueur_max[id_joueur]);
        /// on devra afficher le recap de ses propriétes...
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
                    carre_noir();
                    char phrase_valeur_hypotheque[100] = "Vous recuperer l'argent de la valeur de l'hypoteque de votre propriete hypotequee";
                    longueur = strlen(phrase_valeur_hypotheque);
                    placement_script(longueur,0);
                    printf("%s", phrase_valeur_hypotheque);
                    char phrase_perception_loyer[100] = "Vous ne pouvez desormais plus percevoir le loyer de cette propriete";
                    longueur = strlen(phrase_perception_loyer);
                    placement_script(longueur,2);
                    /// si possible mettre le nom de la propriete a la place de "cette propriete"
                    printf("%s",phrase_perception_loyer);
                    pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + terrain[i][j].val_hypotheque;
                    terrain[i][j].hypotheque ==  true;
                }
            }
            break;
            }
        break;
        }
    }

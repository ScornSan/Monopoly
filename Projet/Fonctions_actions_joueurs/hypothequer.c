#include "../Structures/structure_joueur.h"
/// HYPOTEQUER UNE MAISON :

void hypothequer (t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[])
{
    int touche = 25; // un joueur ne pourra jamais avoir 25 propriete, donc jamais un identifiant de 25
    int fleche2;
    int nb_cartes;
    char phrase_maison_hypotheque[100] = "Si vous avez des maisons sur cette propriete,";
    char phrase_suite[100] = "elle seront revendues a moitie prix";
    while (touche > identifiant_joueur_max[id_joueur] ) // On entre dans le blindage
    {
        char phrase_prop_hypotheque[100] = ", quelle propriete voulez vous hypotequer ?";
        longueur = strlen(phrase_prop_hypotheque) + strlen(pion_joueur[id_joueur].pseudo);
        placement_script(longueur,2);
        printf("%s%s", pion_joueur[id_joueur].pseudo, phrase_prop_hypotheque);
        char phrase_maison_hypotheque[100] = "Si vous avez des maisons sur cette propriete,";
        char phrase_suite[100] = "elle seront revendues a moitie prix";
        placement_script(19,3);
        printf("l id max est de %d : ", identifiant_joueur_max[id_joueur]);
        /// on devra afficher le recap de ses propri�tes...
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
                // le terrain appartient au joueur, il n'est pas hypoth�qu�, et il n'a pas de maisons dessus
                if (touche == terrain[i][j].id_carte && terrain[i][j].hypotheque == false && terrain[i][j].nb_maison == 0)
                {
                    while ( terrain[i][j].nb_maison >= 1 )
                    {
                        terrain[i][j].nb_maison--;
                        pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + (terrain[i][j].prix_maison/2);
                    }
                    carre_noir();
                    char phrase_valeur_hypotheque[100] = ", vous recuperer l'argent de la valeur de l'hypoteque de votre propriete hypotequee ";
                    longueur = strlen(phrase_valeur_hypotheque) + strlen(pion_joueur[id_joueur].pseudo)+ 10;
                    placement_script(longueur,0);
                    printf("%s%s%s",pion_joueur[id_joueur].pseudo, phrase_valeur_hypotheque, terrain[i][j].nom );
                    char phrase_perception_loyer[100] = "Vous ne pouvez desormais plus percevoir le loyer de la propriete";
                    longueur = strlen(phrase_perception_loyer) + 10;
                    placement_script(longueur,2);
                    printf("%s%s", phrase_perception_loyer, terrain[i][j].val_hypotheque);
                    pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + terrain[i][j].val_hypotheque;
                    terrain[i][j].hypotheque ==  true;
                }
                else if (touche == terrain[i][j].id_carte && terrain[i][j].hypotheque == false && terrain[i][j].nb_maison > 0)
                {
                    placement_script(strlen(phrase_suite),4 );
                    printf("%s", phrase_suite);
                    placement_script(19,5);
                }
                else
                {
                    carre_noir();
                    if ( touche != terrain[i][j].id_carte)
                    {
                        char non_possession[100] = "Vous ne possedez pas la propriete ";
                        longueur = strlen(non_possession) + 10; // 10 correspond au nombre de caractere du nom d'une propriete
                        placement_script(longueur,0);
                        printf("%s%s",non_possession, terrain[i][j].nom);
                    }
                    if ( terrain[i][j].hypotheque == true)
                    {
                        char deja_hypotheque[100] = "Vous avez deja hypoteque ce terrain";
                        placement_script(strlen(deja_hypotheque),0);
                        char seconde_chance[100] = "Appuyer sur 'a' pour choisir un autre terrain a hypotequer";
                        placement_script(strlen(seconde_chance),1);
                        if (getch() == 'a' || getch() == 'A')
                        {
                            hypothequer(pion_joueur, max_joueurs, id_joueur, terrain, identifiant_joueur_max);
                        }

                    }
                    break;
                 }
            }
            break;
            }
        break;
        }
    }

#include "../Structures/structure_joueur.h"
/// HYPOTEQUER UNE MAISON :

void hypothequer (t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[], int repere[], int banque_de_carte[])
{
    int touche = 25; // un joueur ne pourra jamais avoir 25 propriete, donc jamais un identifiant de 25
    int selection;
    int fleche2;
    int x;
    int nb_cartes;
    while (touche >= identifiant_joueur_max[id_joueur] || touche == 0) // On entre dans le blindage des proprietes
    {
        char phrase_prop_hypotheque[100] = ", quelle propriete voulez vous hypotequer ?";
        longueur = strlen(phrase_prop_hypotheque) + strlen(pion_joueur[id_joueur].pseudo);
        placement_script(longueur,5);
        printf("%s%s", pion_joueur[id_joueur].pseudo, phrase_prop_hypotheque);
        char phrase_maison_hypotheque[100] = "Si vous avez des maisons sur cette propriete,";
        char phrase_suite[100] = "elles seront automatiquement TOUTES revendues a moitie prix";
        placement_script(strlen(phrase_maison_hypotheque),2);
        printf("%s", phrase_maison_hypotheque, phrase_suite);
        placement_script(strlen(phrase_suite),3);
        printf("%s", phrase_suite);
        fflush(stdin);
        gotoligcol(35,51);
        scanf("%d", &touche);
        if (touche >= identifiant_joueur_max[id_joueur] || touche <= 0)
        {
            carre_noir();
            Color(id_joueur + 1, 0);
            char echec_hypotheque[100] = "Cette propriete ne vous appartient pas";
            placement_script(strlen(echec_hypotheque), 0);
            printf("%s", echec_hypotheque);
            usleep(3000000);
            break;
        }
    }
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
            if (terrain[i][j].id_carte[id_joueur] == touche && terrain[i][j].possession_carte == id_joueur)
            {
                if (terrain[i][j].hypotheque == false)
                {
                    // si le joueur a sélectionné un de ses terrains
                    while (terrain[i][j].nb_maison >= 1)
                    {
                        terrain[i][j].nb_maison--;
                        banque_de_carte[0]++;
                        pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + (terrain[i][j].prix_maison/2);
                    }
                    carre_noir();
                    pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + terrain[i][j].val_hypotheque;
                    affichage_argent_joueurs(pion_joueur, id_joueur);
                    placement_script(strlen(pion_joueur[id_joueur].pseudo), 0);
                    printf("%s,", pion_joueur[id_joueur].pseudo);
                    char phrase_valeur_hypotheque[100] = "vous recuperer l'argent de la valeur de l'hypoteque s'elevant a";
                    longueur = strlen(phrase_valeur_hypotheque);
                    placement_script(longueur,1);
                    printf("%s %d", phrase_valeur_hypotheque, terrain[i][j].val_hypotheque);
                    char phrase_perception_loyer[100] = "Vous ne pouvez desormais plus percevoir le loyer de cette propriete";
                    longueur = strlen(phrase_perception_loyer);
                    placement_script(longueur,3);
                    printf("%s", phrase_perception_loyer);
                    terrain[i][j].hypotheque =  true;
                    affichage_prix_terrain(repere, terrain);
                    affichage_carte(repere, id_joueur, terrain, i, j);
                    usleep(3000000);
                    break;
                }
                else
                {
                    carre_noir();
                    Color(id_joueur + 1, 0);
                    placement_script(strlen(pion_joueur[id_joueur].pseudo), 0);
                    printf("%s,", pion_joueur[id_joueur].pseudo);
                    char echec_hypotheque[100] = "vous avez deja hypotheque la propriete ";
                    placement_script(strlen(echec_hypotheque) + strlen(terrain[i][j].nom) + 2, 1);
                    printf("%s'%s'", echec_hypotheque, terrain[i][j].nom);
                    usleep(3000000);
                    break;
                }
                gotoligcol(38,65);
                Color(0,3);
                printf("%d ", banque_de_carte[0]);
                sleep(3000000);
            }

        }
    }
}

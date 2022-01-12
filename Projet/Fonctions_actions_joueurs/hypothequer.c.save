#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"
/// HYPOTEQUER UNE MAISON :

void hypothequer(t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[], int repere[], int banque_de_carte[], int fin_de_jeu)
{
    int fleche3;
    int touche2 = 0;
    int selection;
    int x;
    int nb_cartes;
    int groupe;
    int prop;
    char phrase_prop_hypotheque[100] = ", quelle propriete voulez vous hypotequer ?";
    longueur = strlen(phrase_prop_hypotheque) + strlen(pion_joueur[id_joueur].pseudo);
    placement_script(longueur,6);
    printf("%s%s", pion_joueur[id_joueur].pseudo, phrase_prop_hypotheque);
    char phrase_maison_hypotheque[100] = "Si vous avez des maisons sur cette propriete,";
    char phrase_suite[100] = "elles seront automatiquement TOUTES revendues a moitie prix";
    placement_script(strlen(phrase_maison_hypotheque),3);
    printf("%s", phrase_maison_hypotheque, phrase_suite);
    placement_script(strlen(phrase_suite),4);
    printf("%s", phrase_suite);
    fflush(stdin);
    fleche3 = getch();
    while (fleche3 != TOUCHE_ENTER)
    {
        // On peut racheter seulement les proprietes que l'on possede, sinon c'est qu'on ne la possede pas
        if ((fleche3 == 'z' || fleche3 == 'Z') && touche2 < identifiant_joueur_max[id_joueur] - 1) // z sert à augmenter de 1 le nombre de maison a vendre
        {
            touche2++;
            usleep(50000);
            Color(repere[2],repere[3]);
            carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
        }
        // On peut racheter seulement les proprietes que l'on possede
        else if ((fleche3 == 's' || fleche3 == 's') && (touche2 == identifiant_joueur_max[id_joueur] || touche2 > 1)) // s sert a diminuer de 1 le nombre de maisons à vendre
        {
            touche2--;
            usleep(50000);
            Color(repere[2],repere[3]);
            carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
        }
        for (int a = 0; a < GROUPES_CARTES; a++)
        {
            if (a % 2 == 0 || a == 1)
            {
                nb_cartes = 2;
            }
            else
            {
                nb_cartes = 3;
            }
            for (int b = 0; b < nb_cartes; b++)
            {
                if (terrain[a][b].possession_carte == id_joueur)
                {
                    if (touche2 == terrain[a][b].id_carte[id_joueur])
                    {
                        char nb_maison[50] = "Propriete selectionne :";
                        longueur = strlen(nb_maison);
                        effacement_perso(0, 1, 60, 37, 30);
                        placement_script(longueur, 8);
                        printf("%d", touche2);
                        printf("%s %s", nb_maison, terrain[a][b].nom);
                        groupe = a;
                        prop = b;
                    }
                }
            }
        }
        fleche3 = getch();    // ajout du compteur fait
    }

    if (terrain[groupe][prop].id_carte[id_joueur] == touche2 && terrain[groupe][prop].possession_carte == id_joueur)
    {
        if (terrain[groupe][prop].hypotheque == false)
        {
            // si le joueur a sélectionné un de ses terrains
            while (terrain[groupe][prop].nb_maison >= 1)
            {
                terrain[groupe][prop].nb_maison--;
                banque_de_carte[0]++;
                pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + (terrain[groupe][prop].prix_maison/2);
            }
            carre_noir();
            pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + terrain[groupe][prop].val_hypotheque;
            affichage_argent_joueurs(pion_joueur, id_joueur);
            placement_script(strlen(pion_joueur[id_joueur].pseudo), 0);
            printf("%s,", pion_joueur[id_joueur].pseudo);
            char phrase_valeur_hypotheque[100] = "vous recuperer l'argent de la valeur de l'hypoteque s'elevant a";
            longueur = strlen(phrase_valeur_hypotheque);
            placement_script(longueur,1);
            printf("%s %d", phrase_valeur_hypotheque, terrain[groupe][prop].val_hypotheque);
            char phrase_perception_loyer[100] = "Vous ne pouvez desormais plus percevoir le loyer de cette propriete";
            longueur = strlen(phrase_perception_loyer);
            placement_script(longueur,3);
            printf("%s", phrase_perception_loyer);
            terrain[groupe][prop].hypotheque =  true;
            affichage_prix_terrain(repere, terrain);
            affichage_carte(repere, id_joueur, terrain, groupe, prop);
            identifiant_joueur_max[id_joueur]--;
            usleep(300000);
        }
        else
        {
            carre_noir();
            Color(id_joueur + 1, 0);
            placement_script(strlen(pion_joueur[id_joueur].pseudo), 0);
            printf("%s,", pion_joueur[id_joueur].pseudo);
            char echec_hypotheque[100] = "vous avez deja hypotheque la propriete ";
            placement_script(strlen(echec_hypotheque) + strlen(terrain[groupe][prop].nom) + 2, 1);
            printf("%s'%s'", echec_hypotheque, terrain[groupe][prop].nom);
            usleep(300000);
        }
    }
}

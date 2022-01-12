#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void rachat_terrain(t_joueur pion_joueur[], int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[], int banque_de_carte[], int repere[])
{
    int touche = 0;
    int fleche;
    int groupe;
    int prop;
    int nb_cartes;
    int compteur = 0;
    int a;
    int b;
    carre_noir();
    char phrase_vente_maison[100] = ", quelle propriete voulez-vous rachetez ?";
    longueur = strlen(phrase_vente_maison) + strlen(pion_joueur[id_joueur].pseudo);
    placement_script(longueur,0);
    printf("%s%s", pion_joueur[id_joueur].pseudo, phrase_vente_maison);
    char chaine_choix[70] = "Appuyez sur 'Z' ou 'S' pour choisir la maison a racheter";
    placement_script(strlen(chaine_choix),2);
    printf("%s", chaine_choix);
    fflush(stdin);
    fleche = getch();

    while (fleche != TOUCHE_ENTER)
    {
        // On peut racheter seulement les proprietes que l'on possede, sinon c'est qu'on ne la possede pas
        if ((fleche == 'z' || fleche == 'Z') && touche < identifiant_joueur_max[id_joueur]) // z sert à augmenter de 1 le nombre de maison a vendre
        {
            touche++;
            usleep(50000);
            Color(repere[2],repere[3]);
            carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
        }
        // On peut racheter seulement les proprietes que l'on possede
        else if ((fleche == 's' || fleche == 's') && (touche == identifiant_joueur_max[id_joueur] || touche > 1)) // s sert a diminuer de 1 le nombre de maisons à vendre
        {
            touche--;
            usleep(50000);
            Color(repere[2],repere[3]);
            carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
        }
        for (a = 0; a < GROUPES_CARTES; a++)
        {
            if (a % 2 == 0 || a == 1)
            {
                nb_cartes = 2;
            }
            else
            {
                nb_cartes = 3;
            }
            for (b = 0; b < nb_cartes; b++)
            {
                if (terrain[a][b].possession_carte == id_joueur)
                {
                    if (touche == terrain[a][b].id_carte[id_joueur])
                    {
                        effacement_perso(0, 1, 20, 35, 64);
                        char nb_maison[50] = "Propriete selectionne :";
                        longueur = strlen(nb_maison);
                        Color(15,0);
                        placement_script(longueur, 6);
                        printf("%s %s", nb_maison, terrain[a][b].nom);
                        groupe = a;
                        prop = b;
                    }
                }
            }
        }
        fleche = getch();    // ajout du compteur fait
    }
    // le terrain est hypotheque et il a assez d'argent, il le rachete
    if (terrain[groupe][prop].hypotheque == true && pion_joueur[id_joueur].argent > terrain[groupe][prop].prix_rachat)
    {
        carre_noir();
        char rachat[50] = "a ete rachete !";
        placement_script(strlen(rachat) + strlen(terrain[groupe][prop].nom) + 2, 0);
        printf("'%s' %s", terrain[groupe][prop].nom, rachat);
        terrain[groupe][prop].hypotheque = false;
        pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent - terrain[groupe][prop].prix_rachat;
        affichage_argent_joueurs(pion_joueur, id_joueur);
        affichage_carte(repere, id_joueur, terrain, groupe, prop);
        affichage_prix_terrain(repere, terrain);
        identifiant_joueur_max[id_joueur]++;
        usleep(5000000);
    }
    // Il ne peut pas racheter un terrain non hypotheque
    else if (terrain[groupe][prop].hypotheque == false)
    {
        carre_noir();
        char echec_rachat[50] = "n'est pas hypotheque !";
        placement_script(strlen(echec_rachat) + strlen(terrain[groupe][prop].nom) + 2, 0);
        printf("'%s' %s", terrain[groupe][prop].nom, echec_rachat);
        affichage_argent_joueurs(pion_joueur, id_joueur);
        usleep(5000000);
    }
    // Il ne peut pas racheter un terrain sans argent
    else
    {
        carre_noir();
        char echec_rachat[70] = ", vous n'avez pas assez d'argent !";
        placement_script(strlen(echec_rachat) + strlen(pion_joueur[id_joueur].pseudo), 0);
        printf("'%s' %s", terrain[groupe][prop].nom, echec_rachat);
        affichage_argent_joueurs(pion_joueur, id_joueur);
        usleep(5000000);
    }

    /*if (touche >= identifiant_joueur_max[id_joueur] || touche <= 0)
    {
        carre_noir();
        Color(id_joueur + 1, 0);
        char echec_hypotheque[100] = "Cette propriete ne vous appartient pas";
        placement_script(strlen(echec_hypotheque), 0);
        printf("%s", echec_hypotheque);
        usleep(3000000);
    }*/
}

#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void vente_maisons(int repere[], t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[])
{
    int touche = 25; // un joueur ne pourra jamais avoir 25 propriete, donc jamais un identifiant de 25
    int fleche2;
    int nb_cartes;
    while (touche >= identifiant_joueur_max[id_joueur] || touche <= 0) // On entre dans le blindage
    {
        carre_noir();
        char phrase_vente_maison[100] = ", sur quel propriete voulez-vous vendre vos maisons ?";
        longueur = strlen(phrase_vente_maison)+strlen(pion_joueur[id_joueur].pseudo);
        placement_script(longueur,0);
        printf("%s%s", pion_joueur[id_joueur].pseudo, phrase_vente_maison);
        placement_script(17,1);
        fflush(stdin);
        scanf("%d", &touche);
        if (touche >= identifiant_joueur_max[id_joueur] || touche <= 0)
        {
            carre_noir();
            Color(id_joueur + 1, 0);
            char echec_vente[100] = "Vous ne possedez pas cette propriete";
            placement_script(strlen(echec_vente), 0);
            printf("%s", echec_vente);
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
            // le joueur selectione sa propriete et elle contient des maisons
            if (terrain[i][j].id_carte[id_joueur] == touche && terrain[i][j].possession_carte == id_joueur)
            {
                char nombre_maison_avendre[100] = "Appuyez sur 'z' ou 's' pour choisir le nombre de maisons a vendre";
                placement_script(strlen(nombre_maison_avendre),3);
                printf("%s",nombre_maison_avendre);
                fflush(stdin);

                int nb = 0;
                fleche2 = getch();
                while (fleche2 != TOUCHE_ENTER) // Tant que ENTER n'est pas press�, on boucle � l'infini
                {
                    // On peut enlever des maisons si il en reste (> 0) et rester bloquer au minimum a 0
                    if ((fleche2 == 'z' || fleche2 == 'Z') && terrain[i][j].nb_maison > 0 && nb > 0) // z sert � augmenter de 1 le nombre de maison a vendre
                    {
                        terrain[i][j].nb_maison--;
                        terrain[i][j].prix_loyer = terrain[i][j].prix_loyer / 2 - 50;
                        pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent + terrain[i][j].prix_maison; // ajout argent
                        usleep(50000);
                        affichage_argent_joueurs(pion_joueur, id_joueur);
                        Color(repere[2],repere[3]);
                        carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                        affichage_maisons(repere,terrain[i][j].nb_maison);
                        affichage_carte(repere, id_joueur, terrain, i , j);
                        nb++;


                    }
                    // On peut enlever des maisons si il en reste (> 0) et rester bloquer au maximum a 4
                    else if ((fleche2 == 's' || fleche2 == 's') && terrain[i][j].nb_maison < 4 && nb < 4) // s sert a diminuer de 1 le nombre de maisons � vendre
                    {
                        terrain[i][j].nb_maison++;
                        terrain[i][j].prix_loyer = terrain[i][j].prix_loyer * 2 + 50;
                        pion_joueur[id_joueur].argent = pion_joueur[id_joueur].argent - terrain[i][j].prix_maison; // retirer argent
                        usleep(50000);
                        affichage_argent_joueurs(pion_joueur, id_joueur);
                        Color(repere[2],repere[3]);
                        carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                        affichage_maisons(repere, terrain[i][j].nb_maison);
                        affichage_carte(repere, id_joueur, terrain, i , j);
                        nb--;
                    }
                    else
                    {
                        carre_noir();
                        Color(id_joueur + 1, 0);
                        char echec_vente2[100] = ", vous ne possedez aucune maison sur cete propriete !";
                        placement_script(strlen(echec_vente2), 0);
                        printf("%s%s", pion_joueur[id_joueur].pseudo);
                        sleep(2);
                        break;
                    }

                    char nb_maison[100] = "Nombre de maison vendues :";
                    longueur = strlen(nb_maison);
                    Color(15,0);
                    placement_script(longueur, 6);
                    printf("%s %d", nb_maison, nb);
                    fleche2 = getch();    // ajout du compteur fait
                }
            }
        }
    }
}

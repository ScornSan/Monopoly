#include "structure_joueur.h"

void identification_terrain(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{
    printf("Vous etes dans la %s\n", terrain[a][b].nom);
    affichage_carte(15,120,terrain,a,b);
            if (terrain[a][b].prop_achete == false && pion_joueur[id_joueurs_v1].argent > terrain[a][b].prix_achat)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire\n");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[a][b].prop_achete = true;
                    terrain[a][b].possession_carte = id_joueurs_v1;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_achat;
                }
            }
            else if (terrain[a][b].prop_achete = true) // paiement du loyer car propriété possedé ou faire une maison / hotel
            {
                if (id_joueurs_v1 == terrain[a][b].possession_carte)
                {
                    printf("Vous etes sur votre propriete !");
                }
                for (int i = 0; i < max_joueurs; i++)
                {
                    if (i == terrain[a][b].possession_carte)
                    {
                        pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_loyer;
                        pion_joueur[i].argent = pion_joueur[i].argent + terrain[a][b].prix_loyer;
                        break;
                    }
                }
            }
            else if (pion_joueur[id_joueurs_v1].argent < terrain[a][b].prix_achat)
            {
                printf("Vous n'avez pas assez d'argent pour acheter '%s'\n", terrain[a][b].nom);
            }
}

void tomber_sur_terrain(t_joueur pion_joueur[], int nb_joueurs, int id_joueurs_v1, t_carte terrain[][3])
{
    printf("On entre dans l'achat terrain\n");
    printf("%d\n", pion_joueur[id_joueurs_v1].position);
    switch (pion_joueur[id_joueurs_v1].position)
    {
        // Chaque cas correspond à l'indice de la position du joueur, dans le tableau correspondant au plateau
        case 1:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 0, 0);
            break;
        case 3:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 0, 1);
            break;
        case 4:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 1, 0);
            break;
        case 6:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 1, 1);
            break;
        case 8:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 2, 1);
            break;
        case 9:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 2, 1);
            break;
        case 10:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 3, 0);
            break;
        case 11:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 3, 1);
            break;
        case 13:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 3, 2);
            break;
        case 15:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 4, 0);
            break;
        case 16:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 4, 1);
            break;
        case 17:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 5, 0);
            break;
        case 18:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 5, 1);
            break;
        case 20:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 5, 2);
            break;
        case 22:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 6, 0);
            break;
        case 23:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 6, 1);
            break;
        case 24:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 7, 0);
            break;
        case 25:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 7, 1);
            break;
        case 27:
            identification_terrain(pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 7, 2);
            break;
    }
}

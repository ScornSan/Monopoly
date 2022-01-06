#include "../Structures/structure_joueur.h"
void identification_terrain(int repere[4], t_joueur pion_joueur[], int max_joueurs, int id_joueurs, t_carte terrain[][3], int a, int b, int identifiant_carte[])
{
    //carre_noir();
    char chaine[100] = "Vous etes dans la ";
    longueur = strlen(chaine) + strlen(terrain[a][b].nom);
    placement_script(longueur,2);
    printf("%s %s",chaine, terrain[a][b].nom);
    usleep(300000);
    if (terrain[a][b].prop_achete == false && pion_joueur[id_joueurs].argent > terrain[a][b].prix_achat)
    {
        char chaine[100] = "Voulez-vous acheter ce terrain?";
        longueur = strlen(chaine);
        placement_script(longueur,4);
        printf("%s",chaine);
        position_choix(longueur,2,"Oui", "Non", "ENTRER", "Autre Touche");
        if (getch() == TOUCHE_ENTER) // 13 est le numéro ascii pour retour charriot, ou ENTER
        {
            terrain[a][b].prop_achete = true;
            terrain[a][b].possession_carte = id_joueurs;
            terrain[a][b].id_carte[id_joueurs] = identifiant_carte[id_joueurs]; // on ajoute un identifiant a la carte acheté
            identifiant_carte[id_joueurs]++; // on ajoute 1 à l'identifiant pour la prochaine carte a acheter du joueur i
            pion_joueur[id_joueurs].argent = pion_joueur[id_joueurs].argent - terrain[a][b].prix_achat;
            affichage_carte(repere, id_joueurs, terrain, a, b, terrain[a][b].hypotheque);
            affichage_argent_joueurs(pion_joueur, id_joueurs);
        }
    }
    else if (terrain[a][b].prop_achete = true && terrain[a][b].hypotheque ==  false) // paiement du loyer car propriété possedé ou faire une maison / hotel
    {
        if (id_joueurs == terrain[a][b].possession_carte && terrain[a][b].nb_maison < 5)
        {
            ajout_maisons(repere, pion_joueur, max_joueurs, id_joueurs, terrain, a, b);
        }
        else if (id_joueurs == terrain[a][b].possession_carte && terrain[a][b].nb_maison == 4)
        {
            ajout_hotel(repere, pion_joueur, max_joueurs, id_joueurs, terrain, a, b);
        }
        else
        {
            paiement_loyer(repere, pion_joueur, max_joueurs, id_joueurs, terrain, a, b, identifiant_carte);
        }
    }
    else if (pion_joueur[id_joueurs].argent < terrain[a][b].prix_achat)
    {
        char chaine[100] = "Vous n'avez pas assez d'argent pour acheter ";
        longueur = strlen(chaine) + strlen(terrain[a][b].nom);
        placement_script(longueur,0);
        printf("%s'%s'\n",chaine, terrain[a][b].nom);
    }
}

void tomber_sur_terrain(int repere [], t_joueur pion_joueur[], int nb_joueurs, int id_joueurs_v1, t_carte terrain[][3], int id_carte[])
{
    switch (pion_joueur[id_joueurs_v1].position)
    {
        // Chaque cas correspond à l'indice de la position du joueur, dans le tableau correspondant au plateau
        case 1:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 0, 0, id_carte);
            break;
        case 3:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 0, 1, id_carte);
            break;

        case 4:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 1, 0, id_carte);
            break;
        case 6:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 1, 1, id_carte);
            break;
        case 8:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 2, 0, id_carte);
            break;
        case 9:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 2, 1, id_carte);
            break;
        case 10:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 3, 0, id_carte);
            break;
        case 11:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 3, 1, id_carte);
            break;
        case 13:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 3, 2, id_carte);
            break;
        case 15:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 4, 0, id_carte);
            break;
        case 16:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 4, 1, id_carte);
            break;
        case 17:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 5, 0, id_carte);
            break;
        case 18:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 5, 1, id_carte);
            break;
        case 20:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 5, 2, id_carte);
            break;
        case 22:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 6, 0, id_carte);
            break;
        case 23:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 6, 1, id_carte);
            break;
        case 24:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 7, 0, id_carte);
            break;
        case 25:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 7, 1, id_carte);
            break;
        case 27:
            identification_terrain(repere, pion_joueur, nb_joueurs, id_joueurs_v1, terrain, 7, 2, id_carte);
            break;
    }
}

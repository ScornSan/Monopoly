#include "../Structures/structure_joueur.h"

void paiement_loyer(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{
    // terrain[a][b].possession_carte est l'indice du joueur qui possède la carte
    carre_noir();
    longueur = strlen(pion_joueur[id_joueurs_v1].pseudo) + strlen(terrain[a][b].nom) + strlen(pion_joueur[terrain[a][b].possession_carte].pseudo) + 36;
    placement_script(longueur,2);
    printf("%s, vous etes sur %s qui appartient a %s !",pion_joueur[id_joueurs_v1].pseudo, terrain[a][b].nom, pion_joueur[terrain[a][b].possession_carte].pseudo);
    longueur = 31;
    placement_script(longueur,4);
    printf("Vous devez payer %d de loyer !", terrain[a][b].prix_loyer);

    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_loyer;
    pion_joueur[terrain[a][b].possession_carte].argent = pion_joueur[terrain[a][b].possession_carte].argent + terrain[a][b].prix_loyer;
}

void ajout_maisons(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{    // modification en chaine
    int fleche1;
    char presence_propriete[100] = ", vous etes sur votre propriete !";
    longueur = strlen(presence_propriete) + 10 + strlen(pion_joueur[id_joueurs_v1].pseudo);
    placement_script(longueur,0);
    printf("%s%s%s",pion_joueur[id_joueurs_v1].pseudo, presence_propriete, terrain[a][b].nom);
    char nb_de_maison[20] = "Vous possedez ";
    char chaine[20] = " maison(s)";
    longueur = strlen(nb_de_maison) + strlen(chaine) + 1;
    placement_script(longueur,1);
    printf("%s%d%s", nb_de_maison, terrain[a][b].nb_maison, chaine);
    char consigne[100] = "Appuyez sur ESPACE pour continuer ou pressez la touche ENTER pour ajouter des maisons";
    placement_script(strlen(consigne),2);

    if (getch() == TOUCHE_ENTER)
    {
        char ajouter_ou_enlever_maisons [100] = "Appuyez sur z ou s pour ajouter ou enlever des maisons a la propriete : ";
        longueur = strlen(ajouter_ou_enlever_maisons) + 10;
        placement_script(longueur,3);
        printf("%s%s", ajouter_ou_enlever_maisons, terrain[a][b].nom);
        char validation[100] = "Appuyez sur ENTRER pour valider";
        longueur = strlen(validation);
        placement_script(longueur,4);
        fflush(stdin);

        while (getch() != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {
            fleche1 = getch();
            if (fleche1 == 'z' && terrain[a][b].nb_maison < 4) // z sert à augmenter de 1 le nombre
            {
                terrain[a][b].nb_maison++;
                printf(" %c", fleche1);
            }
            else if (fleche1 == 's' && terrain[a][b].nb_maison > 0) // s sert a diminuer de 1 le nombre de maisons à faire
            {
                terrain[a][b].nb_maison--;
                printf(" %c", fleche1);
            }
        }
    }
    // ajouter ou retirez maison avec fleches, verifier le prix également
}

void ajout_hotel(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{
    carre_noir();
    char chaine[100] = " , vous etes sur votre propriete ";
    char nb_maison[100] = "Vous possedez 4 maisons";
    longueur = 10 + strlen(pion_joueur[id_joueurs_v1].pseudo) + strlen(chaine);
    placement_script(longueur,0);
    printf("%s%s%s", pion_joueur[id_joueurs_v1].pseudo, chaine, terrain[a][b].nom);
    placement_script(strlen(nb_maison),1);
    printf("%s", nb_maison);
    char ajout_hotel[100] = "Appuyez sur ESPACE pour continuer ou pressez la touche ENTRER pour ajouter un hotel";
    placement_script(strlen(ajout_hotel),2);
    printf("%s", ajout_hotel);

    if (getch() == TOUCHE_ENTER)
    {
        fflush(stdin);
        char remplacer[100] = "Appuyez sur z ou s pour remplacer ou non les maisons par un hotel sur la case : ";
        placement_script(strlen(remplacer),4);
        printf("%s%s", remplacer, terrain[a][b].nom);

        while (getch() != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {
            if (getch() == 'z' && terrain[a][b].nb_maison < 5)
            {
                terrain[a][b].nb_maison++;
            }
            else if (getch() == 's' && terrain[a][b].nb_maison > 4)
            {
                terrain[a][b].nb_maison--;
            }
        }
    }
    else if (getch() == TOUCHE_ESPACE)
    {

    }
}

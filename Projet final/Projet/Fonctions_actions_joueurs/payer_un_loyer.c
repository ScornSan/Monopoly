#include "../Structures/structure_joueur.h"

void paiement_loyer(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{
    // terrain[a][b].possession_carte est l'indice du joueur qui possède la carte
    printf("%s, vous etes sur %s qui appartient a %s !\n"
           "Vous devez payer %d de loyer !\n", pion_joueur[id_joueurs_v1].pseudo, terrain[a][b].nom, pion_joueur[terrain[a][b].possession_carte].pseudo, terrain[a][b].prix_loyer);

    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_loyer;
    pion_joueur[terrain[a][b].possession_carte].argent = pion_joueur[terrain[a][b].possession_carte].argent + terrain[a][b].prix_loyer;
}

void ajout_maisons(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{
    int fleche1;
    printf("Vous etes sur votre propriete ! Vous possedez %d maison(s) !\n"
           "Appuyez sur ESPACE pour continuer ou pressez la touche ENTER pour ajouter des maisons", terrain[a][b].nb_maison);
    if (getch() == TOUCHE_ENTER)
    {
        printf("Appuyez sur z ou s pour ajouter ou enlever des maisons a la propriete : %s"
               "Appuyez sur ENTRER pour valider", terrain[a][b].nom);
        fflush(stdin);
        while (getch() != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {
            fleche1 = getch();
            if (fleche1 == 'z' && terrain[a][b].nb_maison < 4) // z sert à augmenter de 1 le nombre
            {
                terrain[a][b].nb_maison++;
                printf(" ");
                printf("%d", fleche1);
            }
            else if (fleche1 == 's' && terrain[a][b].nb_maison > 0) // s sert a diminuer de 1 le nombre de maisons à faire
            {
                terrain[a][b].nb_maison--;
                printf(" ");
                printf("%d", fleche1);
            }
        }
    }
    // ajouter ou retirez maison avec fleches, verifier le prix également
}

void ajout_hotel(t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
{
    printf("Vous etes sur votre propriete ! Vous possedez 4 maisons\n"
           "Appuyez sur ESPACE pour continuer ou pressez la touche ENTER pour ajouter un hotel");
    if (getch() == TOUCHE_ENTER)
    {
        fflush(stdin);
        printf("Appuyez sur z ou s pour remplacer ou non les maisons par un hotel sur la case : %s", terrain[a][b].nom);
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

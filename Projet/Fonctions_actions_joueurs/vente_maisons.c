#include "../Structures/structure_joueur.h"

void vente_maisons(t_joueur pion_joueur[], int max_joueurs, int id_joueur, t_carte terrain[][3], int identifiant_joueur_max[])
{
    int touche = 25; // un joueur ne pourra jamais avoir 25 propriete, donc jamais un identifiant de 25
    int fleche2;
    int nb_cartes;

    while (touche > identifiant_joueur_max[id_joueur]) // On entre dans le blindage
    {
        carre_noir(); //
        char phrase_vente_maison[100] = ", sur quel propriete voulez-vous vendre vos maisons ?"; //
        longueur = strlen(phrase_vente_maison)+strlen(pion_joueur[id_joueur].pseudo); //
        placement_script(longueur,0); //
        printf("%s%s", pion_joueur[id_joueur].pseudo, phrase_vente_maison); //
        placement_script(17,1); //
        printf("l id max est de %d", identifiant_joueur_max[id_joueur]); //
        fflush(stdin);
        scanf("%d", &touche);
    }
    while (touche <= identifiant_joueur_max[id_joueur] && (touche > 0 && touche < 6))
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
                if (terrain[i][j].nb_maison >= 1 && touche == terrain[i][j].id_carte)
                {
                    char nombre_maison_avendre[100] = "Appuyez sur 'z' ou 's' pour choisir le nombre de maisons a vendre";
                    placement_script(strlen(nombre_maison_avendre),3);
                    printf("%s",nombre_maison_avendre);
                    /// il faut rajouter la phrase qui explique  que z augmente et s diminue
                    ///donc faudra rajouter un compteur qui commence a 0 qui s'affiche et qui est relié a la lecture de z et s
                    /// ou sinn faire une saisi avec des chiffres et pas z et s
                    fflush(stdin);
                    while (getch() != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
                    {
                        fleche2 = getch();
                        if (fleche2 == 'z' && terrain[i][j].nb_maison < 4) // z sert à augmenter de 1 le nombre
                        {
                            terrain[i][j].nb_maison++;
                            carre_noir();
                            placement_script(2, 0);
                            printf("%c", fleche2);
                        }
                        else if (fleche2 == 's' && terrain[i][j].nb_maison > 0) // s sert a diminuer de 1 le nombre de maisons à faire
                        {
                            terrain[i][j].nb_maison--;
                            carre_noir();
                            placement_script(2, 0);
                            printf("%c", fleche2);
                        }
                    }
                }
                else
                {
                    char maison_sur_prop[100] = "Vous n'avez pas de maisons sur cette propriete !"; //
                    placement_script(strlen(maison_sur_prop),3);/// rajouter le nom de la prop
                    printf("%s",maison_sur_prop); //
                    break;
                }
                break;
            }
            break;
        }
        break;
    }
}

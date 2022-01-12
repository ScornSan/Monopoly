#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void paiement_loyer(int repere[], t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b,  int id_carte[], int banque_de_carte[], bool elimination[])
{
    // terrain[a][b].possession_carte est l'indice du joueur qui possède la carte
    carre_noir();
    if (pion_joueur[id_joueurs_v1].argent > terrain[a][b].prix_loyer)
    {
        longueur = strlen(pion_joueur[id_joueurs_v1].pseudo) + strlen(terrain[a][b].nom) + strlen(pion_joueur[terrain[a][b].possession_carte].pseudo) + 36;
        placement_script(longueur,2);
        printf("%s, vous etes sur %s qui appartient a %s !",pion_joueur[id_joueurs_v1].pseudo, terrain[a][b].nom, pion_joueur[terrain[a][b].possession_carte].pseudo);
        longueur = 31;
        placement_script(longueur,4);
        printf("Vous devez payer %d de loyer !", terrain[a][b].prix_loyer);
        sleep(1);

        pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_loyer;
        pion_joueur[terrain[a][b].possession_carte].argent = pion_joueur[terrain[a][b].possession_carte].argent + terrain[a][b].prix_loyer;
        affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
    }
    else
    {
        int dette = terrain[a][b].prix_loyer;
        int nb_cartes;
        int compteur = 0;
        char manque_argent[50] = " Vous n avez pas assez d argent pour payez le loyer";
        char phrase_prop_vente[50] = " Appuyez sur 'v' pour vendre une propriete";
        char phrase_prop_hypotheque[50] = " Appuyez sur 'h' pour hypothequer une propriete";
        char possession_restant[50] = ", il vous reste la proprietete";
        char possession_restant_nul[50] = ", il ne vous reste aucune proprietete";
        placement_script(strlen(manque_argent), 0);
        printf("%s", manque_argent);
        placement_script(strlen(phrase_prop_vente), 1);
        printf("%s", phrase_prop_vente);
        placement_script(strlen(phrase_prop_hypotheque), 2);
        printf("%s", phrase_prop_hypotheque);

        faillite(pion_joueur, id_joueurs_v1, max_joueurs, terrain, id_carte, dette, banque_de_carte, repere, elimination);
        /*int key = getch();
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
                if (terrain[i][j].possession_carte == id_joueurs_v1)
                {
                    carre_noir();
                    placement_script(strlen(possession_restant_nul), compteur);
                    printf("%s%s",  pion_joueur[id_joueurs_v1].pseudo, possession_restant);
                    compteur++;
                }
                else
                {
                    carre_noir();
                    placement_script(strlen(possession_restant_nul), 0);
                    printf("%s%s",  pion_joueur[id_joueurs_v1].pseudo, possession_restant_nul);
                    pion_joueur[id_joueurs_v1].argent = 0;
                    break;
                }
            }
        }
        if (key == 'h' || key == 'H')
        {
            carre_noir();
            char chaine[100] = " a demande une Hypotheque !";
            int longueur = strlen(chaine) + strlen(pion_joueur[id_joueurs_v1].pseudo) ;
            placement_script(longueur,0);
            printf("%s%s",pion_joueur[id_joueurs_v1].pseudo, chaine);
            hypothequer(pion_joueur, max_joueurs, id_joueurs_v1, terrain, id_carte, repere);
        }

        if (key == 'v' || key == 'V')
        {
            carre_noir();
            char chaine[100] = " a demande une Vente !";
            int longueur = strlen(chaine) + strlen(pion_joueur[id_joueurs_v1].pseudo);
            placement_script(longueur,0);
            printf("%s%s",pion_joueur[id_joueurs_v1].pseudo, chaine);
            //vente_maisons(pion_joueur, max_joueurs, id_joueurs_v1, terrain, id_carte, repere);
        }*/
    }
}

void ajout_maisons(int repere[4], t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b, int id_carte[], int banque_de_carte[])
{
    // modification en chaine
    int fleche1;
    carre_noir();
    char presence_propriete[100] = ", vous etes sur votre propriete ";
    longueur = strlen(presence_propriete) + 10 + strlen(pion_joueur[id_joueurs_v1].pseudo);
    placement_script(longueur,0);
    printf("%s%s%s !",pion_joueur[id_joueurs_v1].pseudo, presence_propriete, terrain[a][b].nom);
    char nb_de_maison[20] = "Vous possedez ";
    char chaine[20] = " maison(s)";
    longueur = strlen(nb_de_maison) + strlen(chaine) + 1;
    placement_script(longueur,1);
    printf("%s%d%s", nb_de_maison, terrain[a][b].nb_maison, chaine);
    char consigne[100] = "Appuyez sur ESPACE pour continuer ou sur ENTRER pour ajouter des maisons";  ////////
    placement_script(strlen(consigne),2);
    printf("%s", consigne);
    position_choix(strlen(consigne),4,"Continuer","Ajouter une maison","ESPACE","ENTRER");

    if (getch() == TOUCHE_ENTER)
    {
        carre_noir();
        char ajouter_ou_enlever_maisons [100] = "Appuyez sur z ous s pour ajouter ou enlever une maison a votre propriete.";
        longueur = strlen(ajouter_ou_enlever_maisons);
        placement_script(longueur,3);
        printf(" %s", ajouter_ou_enlever_maisons);
        char validation[100] = "Appuyez sur ENTRER pour valider";
        longueur = strlen(validation);
        placement_script(longueur,4);
        fflush(stdin);

        liaison_memoire_affichage(repere,a,b);
        fleche1 = getch();
        int nb = 0; //
        while (fleche1 != TOUCHE_ENTER && pion_joueur[id_joueurs_v1].argent > terrain[a][b].prix_maison) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {

            /// On ajoute des maisons
            if (terrain[a][b].nb_maison < 4 && (fleche1 == 'z' || fleche1 == 'Z') && nb < 4 && pion_joueur[id_joueurs_v1].argent > terrain[a][b].prix_maison) // z sert à augmenter de 1 le nombre //
            {
                if (banque_de_carte[0] == 0)
                {
                    char maison_limite[100] = "Le nombre de maisons maximums sur le plateau est atteint !";
                    longueur = strlen(maison_limite);
                    placement_script(longueur, 4);
                    printf( "%s", maison_limite);
                    sleep(2);
                    break;
                }
                else
                {
                    banque_de_carte[0]--;
                    terrain[a][b].nb_maison++;
                    terrain[a][b].prix_loyer = terrain[a][b].prix_loyer + 150;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_maison; // retirer argent
                    usleep(50000);
                    affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
                    Color(repere[2],repere[3]);
                    carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                    affichage_maisons(repere,terrain[a][b].nb_maison);
                    affichage_carte(repere, id_joueurs_v1,terrain, a, b);
                    nb++;
                }
            }
            /// On enleve des maisons
            else if ((fleche1 == 's' || fleche1 == 'S') && terrain[a][b].nb_maison > 0 && nb > 0) // s sert a diminuer de 1 le nombre de maisons à faire  //
            {
                banque_de_carte[0]++;
                terrain[a][b].nb_maison--;
                terrain[a][b].prix_loyer = terrain[a][b].prix_loyer - 150;
                pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent + terrain[a][b].prix_maison; // ajout argent
                usleep(50000);
                affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
                Color(repere[2],repere[3]);
                carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                affichage_maisons(repere,terrain[a][b].nb_maison);
                affichage_carte(repere, id_joueurs_v1,terrain, a, b);
                nb--;
            }
            char nb_maison[50] = "Nombre de maison ajoutees :";
            longueur = strlen(nb_maison);
            Color(15,0);
            placement_script(longueur, 6);
            printf("%s %d", nb_maison, nb);
            fleche1 = getch();    // ajout du compteur fait
        }
        if (pion_joueur[id_joueurs_v1].argent < terrain[a][b].prix_maison)
        {
            char ruiner[150] = "Vous n'avez pas assez d'argent pour acheter d'autres maisons";
            longueur = strlen(ruiner);
            placement_script(longueur, 2);
            printf("%s", ruiner);
            sleep(2);
        }
    }
}

void ajout_hotel(int repere[4], t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b, int id_carte[], int banque_de_carte[])
{
    carre_noir();
    int fleche3;
    char chaine[100] = " , vous etes sur votre propriete ";
    char nb_maison[100] = "Vous possedez 4 maisons";
    longueur = 10 + strlen(pion_joueur[id_joueurs_v1].pseudo) + strlen(chaine);
    placement_script(longueur,0);
    printf("%s%s%s", pion_joueur[id_joueurs_v1].pseudo, chaine, terrain[a][b].nom);
    placement_script(strlen(nb_maison),1);
    printf("%s", nb_maison);
    char phrase_ajout_hotel[100] = "Appuyez sur ESPACE pour continuer ou sur ENTRER pour ajouter un hotel";
    placement_script(strlen(phrase_ajout_hotel),2);
    printf("%s", phrase_ajout_hotel);
    position_choix(strlen(phrase_ajout_hotel),4,"Continuer","Ajouter un hotel","ESPACE","ENTRER");

    if (getch() == TOUCHE_ENTER)
    {
        fflush(stdin);
        carre_noir();
        char remplacer[100] = "Appuyez sur z pour ajouter un hotel ou sur s pour annuler et continuer ";
        placement_script(strlen(remplacer),0);
        printf("%s", remplacer);
        char valider[100] = "Appuyez ensuite sur ENTRER pour valider";
        placement_script(strlen(valider),1);
        printf("%s", valider);
        liaison_memoire_affichage(repere,a,b);
        int valeur_tampon = terrain[a][b].nb_maison;
        fleche3 = getch();
        int nb = 0; //
        while (fleche3 != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {
            /// On ajoute un hotel, retire 4 maisons
            if ((fleche3 == 'z' || fleche3 == 'Z') && nb < 1)
            {
                if (banque_de_carte[1] == 0)
                {
                    char maison_limite[100] = "Le nombre d'hotels maximums sur le plateau est atteint !";
                    longueur = strlen(maison_limite);
                    placement_script(longueur, 4);
                    printf( "%s", maison_limite);
                    sleep(2);
                    break;
                }
                else
                {
                    terrain[a][b].nb_maison = 5;
                    terrain[a][b].prix_loyer = terrain[a][b].prix_loyer + 200;
                    banque_de_carte[0] = banque_de_carte[0] + 4;
                    banque_de_carte[1] = banque_de_carte[1] - 1;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_maison ; // ajout argent
                    affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
                    Color(repere[2],repere[3]);
                    carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                    affichage_hotel(repere);
                    affichage_carte(repere, id_joueurs_v1,terrain, a, b);
                    nb++;
                }

            }
            /// On retire un hotel, rajoute 4 maisons
            else if ((fleche3 == 's' || fleche3 == 'S')&& nb > 0)
            {
                terrain[a][b].nb_maison = 4;
                terrain[a][b].prix_loyer = terrain[a][b].prix_loyer - 200;
                Color(repere[2],repere[3]);
                banque_de_carte[0] = banque_de_carte[0] - 4;
                banque_de_carte[1] = banque_de_carte[1] + 1;
                carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                affichage_maisons(repere,valeur_tampon);
                affichage_carte(repere, id_joueurs_v1,terrain, a, b);
                nb--;
            }
            Color(15,0);
            char nb_maison[50] = "Vous allez ajouter";
            longueur = strlen(nb_maison);
            placement_script(longueur +7, 6);
            printf("%s %d Hotel !", nb_maison, nb);
            fleche3 = getch();    // ajout du compteur fait
        }
        gotoligcol(35,65);
        Color(0,15);
        printf("%d %d", banque_de_carte[0], banque_de_carte[1]);
        sleep(1);
    }
    else if (getch() == TOUCHE_ESPACE)
    {

    }
}

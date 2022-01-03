#include "../Structures/structure_joueur.h"
#include "../Fonctions_affichage/affichage.h"

void paiement_loyer(int repere[4], t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b,  int id_carte[])
{
    // terrain[a][b].possession_carte est l'indice du joueur qui possède la carte
    carre_noir();
    if ( pion_joueur[id_joueurs_v1].argent > terrain[a][b].prix_loyer )
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
    }
    else
    {
        char manque_argent[50] = " Vous n avez pas assez d argent pour payez le loyer";
        char phrase_prop_vente[50] = " Appuyez sur 'v' pour vendre une propriete";
        char phrase_prop_hypotheque[50] = " Appuyez sur 'h' pour hypothequer une propriete";
        placement_script(strlen(manque_argent), 0);
        printf("%s", manque_argent);
        placement_script(strlen(phrase_prop_vente), 1);
        printf("%s", phrase_prop_vente);
        placement_script(strlen(phrase_prop_hypotheque), 2);
        printf("%s", phrase_prop_hypotheque);
        int key = getch();

        if (key == 'h' || key == 'H')
        {
            carre_noir();
            char chaine[100] = " a demande une Hypotheque !";
            int longueur = strlen(chaine) + strlen(pion_joueur[id_joueurs_v1].pseudo) ;
            placement_script(longueur,0);
            printf("%s%s",pion_joueur[id_joueurs_v1].pseudo, chaine);
            hypothequer(repere, pion_joueur, max_joueurs, id_joueurs_v1, terrain, id_carte);
        }

        if (key == 'v' || key == 'V')
        {
            carre_noir();
            char chaine[100] = " a demande une Vente !";
            int longueur = strlen(chaine) + strlen(pion_joueur[id_joueurs_v1].pseudo);
            placement_script(longueur,0);
            printf("%s%s",pion_joueur[id_joueurs_v1].pseudo, chaine);
            vente_maisons(repere, pion_joueur, max_joueurs, id_joueurs_v1, terrain, id_carte);

        }
    }
}

void ajout_maisons(int repere[4], t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
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
        char ajouter_ou_enlever_maisons [100] = "Appuyez sur z pour ajouter ou s pour enlever une maison a votre propriete.";
        longueur = strlen(ajouter_ou_enlever_maisons);
        placement_script(longueur,3);
        printf(" %s", ajouter_ou_enlever_maisons);
        char validation[100] = "Appuyez sur ENTRER pour valider";
        longueur = strlen(validation);
        placement_script(longueur,4);
        fflush(stdin);

        liaison_memoire_affichage(repere,a,b);
        fleche1 = getch();
        while (fleche1 != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {
            int nb = 0; //
            fleche1 = getch();    // ajout du compteur fait

            if (terrain[a][b].nb_maison < 4 && terrain[a][b].nb_maison > 0 && (fleche1 == 'z' || fleche1 == 'Z') && nb < 4) // z sert à augmenter de 1 le nombre //
            {
                terrain[a][b].nb_maison++;
                pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_maison; // ajout argent
                affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
                Color(repere[2],repere[3]);
                carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                affichage_maisons(repere,terrain[a][b].nb_maison);
                nb++;

            }
            if ((fleche1 == 's' || fleche1 == 'S') && terrain[a][b].nb_maison > 0 && terrain[a][b].nb_maison < 4 && nb > 0) // s sert a diminuer de 1 le nombre de maisons à faire  //
            {
                terrain[a][b].nb_maison--;
                pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent + terrain[a][b].prix_maison; // ajout argent
                affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
                Color(repere[2],repere[3]);
                carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                affichage_maisons(repere,terrain[a][b].nb_maison);
                nb--;
            }

            carre_noir();
            char nb_maison = "Nombre de maison ajoutees : %d";
            longueur = strlen(nb_maison);
            placement_script(longueur, 0);
            printf("%s""%d", nb_maison, nb);

        }
    }
    // ajouter ou retirez maison avec fleches, verifier le prix également
}

void ajout_hotel(int repere[4], t_joueur pion_joueur[], int max_joueurs, int id_joueurs_v1, t_carte terrain[][3], int a, int b)
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
    position_choix(strlen(ajout_hotel),4,"Continuer","Ajouter un hotel","ESPACE","ENTRER");

    if (getch() == TOUCHE_ENTER)
    {
        /// meme beug que maison a regler
        fflush(stdin);
        carre_noir();
        char remplacer[100] = "Appuyez sur z pour remplacer les maisons par un hotel ou sur s pour annuler et continuer ";
        placement_script(strlen(remplacer),0);
        printf("%s", remplacer);
        int valeur_tampon = terrain[a][b].nb_maison;
        while (getch() != TOUCHE_ENTER) // Tant que ENTER n'est pas pressé, on boucle à l'infini
        {
            liaison_memoire_affichage(repere,a,b);
            if (getch() == 'z' || getch() == 'Z')
            {
                terrain[a][b].nb_maison = 5;
                pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[a][b].prix_maison ; // ajout argent
                affichage_argent_joueurs(pion_joueur, id_joueurs_v1);
                Color(repere[2],repere[3]);
                carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                affichage_hotel(repere,terrain[a][b].nb_maison);
            }
            else if (getch() == 's' || getch() == 'S')
            {
                terrain[a][b].nb_maison = 4; // PROBLEME C PAS CA QUI BOUGE
                Color(repere[2],repere[3]);
                carre_couleur(repere[0]+AJUSTEMENT_LIGNE,repere[1]+ AJUSTEMENT_COLONNE);
                affichage_maisons(repere,valeur_tampon);
            }
        }
    }
    else if (getch() == TOUCHE_ESPACE)
    {

    }
}

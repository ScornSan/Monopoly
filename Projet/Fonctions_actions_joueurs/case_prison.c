#include "../Structures/structure_joueur.h"

void effacement_pion_prison(int id_joueur)
{
    Color(0, 15);
    if (id_joueur == 0)
    {
        gotoligcol(47,11);
    }
    if (id_joueur == 1)
    {
        gotoligcol(47,7);
    }
    if (id_joueur == 2)
    {
        gotoligcol(49,11);
    }
    if (id_joueur == 3)
    {
        gotoligcol(49,7);
    }
    printf(" ");
}

void case_prison(t_joueur joueur[], int nombre_joueurs, int id_joueur, int de1, int de2, int nb_tour[])
{
    if (de1 == de2)
    {
        carre_noir();
        longueur = 23;
        placement_script(longueur,0);
        printf("Vous avez fait %d et %d !", de1, de2);
        char phrase_sortie_prison_double[100] = "Vous sortez de prison en faisant un double !";
        longueur = strlen(phrase_sortie_prison_double); //
        placement_script(longueur,1);
        printf("%s",phrase_sortie_prison_double);
        joueur[id_joueur].prison = false;
        usleep(500000);
        joueur[id_joueur].ancienne_position = joueur[id_joueur].position;
        joueur[id_joueur].position += lancer_de(&de1, &de2); // on lance les d�s
        effacement_pion_prison(id_joueur);
        deplacement_joueur(joueur, nombre_joueurs, id_joueur);
    }
    // else if (carte sortie de prison)
    else if (joueur[id_joueur].argent > 50 && nb_tour[id_joueur] < 3)
    {
        carre_noir();
        char phrase_payement_prison[100] = "Voulez-vous payez 50$ pour sortir de prison ?";
        longueur = strlen(phrase_payement_prison);
        placement_script(longueur,0);
        printf("%s",phrase_payement_prison);
        position_choix(longueur,2,"Oui","Non","ENTRER","Autre");
        if (getch() == TOUCHE_ENTER)
        {
            carre_noir();
            char phrase_sortie_prison[100] = "Felicitation ! Vous etes de nouveau libre !";
            longueur = strlen(phrase_sortie_prison);
            placement_script(longueur, 0);
            printf("%s",phrase_sortie_prison);
            ///printf("Vous avez fait %d et %d ! Vous sortez de prison en faisant un double !\n", de1, de2);
            joueur[id_joueur].argent -= 50;
            joueur[id_joueur].prison = false;
            joueur[id_joueur].ancienne_position = joueur[id_joueur].position;
            joueur[id_joueur].position += lancer_de(&de1, &de2); // on lance les d�s
            effacement_pion_prison(id_joueur);
            deplacement_joueur(joueur, nombre_joueurs, id_joueur);
        }
    }
    else if (joueur[id_joueur].argent > 50 && nb_tour[id_joueur] == 3)
    {
        carre_noir();
        char troisieme_tour[100] = "C'est votre troisieme tour en prison, vous sortez en payant 50$";
        placement_script(strlen(troisieme_tour),0);
        printf("%s",troisieme_tour);
        nb_tour[id_joueur] = 0;
        sleep(1);
        joueur[id_joueur].prison = false;
        joueur[id_joueur].ancienne_position = joueur[id_joueur].position;
        joueur[id_joueur].position += lancer_de(&de1, &de2); // on lance les d�s
        effacement_pion_prison(id_joueur);
        deplacement_joueur(joueur, nombre_joueurs, id_joueur);
    }
    else if (joueur[id_joueur].argent < 50)
    {

    }
}

#include "affichage_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "structure_joueur.h"
#include "nouvelle_partie.h"
#include"../partie_en_cours.h"

void affichage_Menu ()
{
    t_joueur tabjoueur[4]; //tableau de structure de joueur
    FILE * fichier_regles; // pointeur sur le fichier qui contient les règles
    int choix = 0;
    int nombre_de_joueurs;
    affichage_choix();
    // SAISIE DU CHOIX
    scanf("%d", &choix);

    // Blindage de la saisie
     while (choix < 1 || choix > 6)
     {
        gotoligcol(16,45);
        printf("INVALIDE ! Entrez votre selection : ");
        fflush(stdin);
        scanf("%d", &choix);
     }

     system("cls");

     switch(choix)
     {
        case 1 :

            system("cls");
            //nouvelle_partie();
            fflush(stdin);
            system("cls");
            partie_en_cours();
            echap();
            /// AJOUTER FONCTION NOUVELLE PARTIE
            break;

        case 2 :
            fflush(stdin);
            // Ajouter fonction sauvegarde partie
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");
            break;

        case 3 :
            fflush(stdin);

            // AJOUTER PROGRAMME QUI REPREND UNE ANCIENNE PARTIE
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");
            break;

        case 4 :
            fflush(stdin);
            fichier_regles = fopen("reglesDuJeu.txt", "r");
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");

            couleur(15, 0);
            if (fichier_regles == NULL)
            {
                printf("Erreur fopen \n");
            }

            char c = fgetc(fichier_regles);
            while( c != EOF) // EOF detecte le dernier caractere du fichier
            {
                printf("%c", c);
                c = fgetc(fichier_regles);
            }
            fclose(fichier_regles); // on ferme le fichier

            break;

        case 5 :
                fflush(stdin);
                couleur(12, 0);
                printf("Appuyez sur [ECHAP] pour revenir au menu");
                couleur(15, 0);
                gotoligcol(10,70);
                printf("Programmeurs de ce jeu : \n");
                gotoligcol(12,70);
                printf("Yohan MARCEL \n");
                gotoligcol(13,70);
                printf("Sarah BLIN \n");
                gotoligcol(14,70);
                printf("Clement POMPEI \n");
                gotoligcol(15,70);
                printf("Benjamin GENDRY \n");
                couleur(10, 0);
                break;


         case 6 :
                exit(0);
        }

        echap();
}

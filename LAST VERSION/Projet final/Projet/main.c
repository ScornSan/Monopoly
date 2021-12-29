#include "Structures/structure_joueur.h"
#include "Affichage_plateau/affichage_plateau.h"

void affichage_Menu()
{
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    FILE * fichier_regles; // pointeur sur le fichier qui contient les r�gles
    int choix = 0;
    int nombre_de_joueurs;
    affichage_choix();
    // SAISIE DU CHOIX
    // Blindage de la saisie
     while (choix < 1 || choix > 6)
     {
        gotoligcol(16,70);
        printf("Entrez votre selection : ");
        fflush(stdin);
        scanf("%d", &choix);
     }
     system("cls");

     switch(choix)
     {
        case 1 :

            system("cls");
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
            fichier_regles = fopen("Menu/reglesDuJeu.txt", "r");
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

int main()
{
    affichage_Menu();
    return 0;
}
#include "Structures/structure_joueur.h"
#include "Affichage_plateau/affichage_plateau.h"

void affichage_Menu()
{
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    FILE * fichier_regles; // pointeur sur le fichier qui contient les règles
    int choix = 0;
    int repere[4]; //////
    int choixsauv = 0;
    int choixcharge = 0;
    int nombre_de_joueurs = 0;
    t_joueur joueur_x[nombre_de_joueurs];
    t_carte cartes;
    void affichage_choix();
    affichage_choix();
    // SAISIE DU CHOIX
    // Blindage de la saisie
     while (choix < 1 || choix > 6)
     {
        system("cls");
        affichage_choix();
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
            partie_en_cours(repere);

            /// AJOUTER FONCTION NOUVELLE PARTIE
            break;

        case 2 :
            // Sauvegarde d'une partie (2 Emplacements)
            while (nombre_de_joueurs == 0) // Verifier si une partie a été joué car on en peu pas sauvegarder à peine arrivé !
            {
                printf("Impossible ! Aucune partie n'est en cours !");
                break;

                if (nombre_de_joueurs != 0)
                {
                    fflush(stdin);
                // Ajout (Clément)
                    printf("Voulez-vous sauvegarder votre partie ?\n");
                    printf("[1] Emplacement 1 ?\n");
                    printf("[2] Emplacement 2 ?\n");
                    scanf("%d", &choixsauv);

                    while (choixsauv != 1 && choixsauv != 2)
                    {
                        printf("ERREUR : Choisir un emplacement correct pour votre sauvegarde.\n");
                        printf("[1] Emplacement 1 ?\n");
                        printf("[2] Emplacement 2 ?\n");
                        scanf("%d", &choixsauv);
                    }
                    if (choixsauv == 1)
                    {
                        sauvegardeclassique(nombre_de_joueurs, *joueur_x); // Passe en pointeur car c'est un tableau
                        printf("Sauvegarde dans l'emplacement 1 faite avec succes !\n");
                    }
                    if (choixsauv == 2)
                    {
                        sauvegardeenplus(nombre_de_joueurs, *joueur_x);
                        printf("Sauvegarde dans l'emplacement 2 faite avec succes !\n");
                    }
                    couleur(12, 0);
                    printf("Appuyez sur [ECHAP] pour revenir au menu");

                    }

            }
            break;


        case 3 :
            // Charge de partie
            fflush(stdin);
            printf("Voulez-vous charger une partie ?\n");
            printf("[1] Charge 1 ?\n");
            printf("[2] Charge 2 ?\n");
            scanf("%d", &choixsauv);

            while (choixcharge != 1 && choixcharge != 2)
            {
                printf("ERREUR : Saisir le nom d'un fichier correct.\n");
                printf("[1] Charge 1 ?\n");
                printf("[2] Charge 2 ?\n");
                scanf("%d", &choixsauv);
                if (choixsauv == 1)
                {
                    chargerpartie1(nombre_de_joueurs, *joueur_x, cartes);
                }
                if (choixsauv == 2)
                {
                    chargerpartie2(nombre_de_joueurs, *joueur_x, cartes);
                }
            }
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
                printf("Erreur d'ouverture fichier. Veuillez réesayer. \n");
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

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void couleur(int couleurTexte,int couleurFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurFond*16+couleurTexte);
}

void gotoligcol( int lig, int col )
{
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}
void affichage_choix()
{
    gotoligcol(5,50);
    couleur(12, 0);
    printf("=======================\n");
    gotoligcol(6,52);
    couleur(15, 0);
    printf("   MENU MONOPOLY  \n");
    gotoligcol(7,50);
    couleur(12, 0);
    printf("=======================\n");
    couleur(15, 0);
    gotoligcol(9,40);
    printf("1- Lancer une nouvelle partie \n");
    gotoligcol(10,40);
    printf("2- Sauvegarder la partie en cours\n");
    gotoligcol(11,40);
    printf("3- Charger une ancienne partie \n");
    gotoligcol(12,40);
    printf("4- Afficher les regles \n");
    gotoligcol(13,40);
    printf("5- Afficher le nom des membres de l equipe du projet \n");
    gotoligcol(14,40);
    printf("6- Quitter\n");
    gotoligcol(15,40);
    couleur(12, 0);
    printf(">>>>\n");
    gotoligcol(15,45);
}
// FONCTION AFFICHAGE DU MENU

void affichage_Menu ()
{

    FILE * fichier_regles;
    int choix = 0;
    affichage_choix();

    // SAISIE DU CHOIX
    scanf("%d", &choix);

    // Blindage de la saisie
    while (choix < 1 || choix > 6)
     {
        gotoligcol(14,45);
        printf("INVALIDE ! Entrez votre selection : ");
        fflush(stdin);
        scanf("%d", &choix);
     }
     system("cls");

     switch(choix)
     {
        case 1 :
            couleur(15, 0);
            gotoligcol(10,45);
            printf("BIENVENUE DANS UNE NOUVELLE PARTIE ! \n");
            gotoligcol(12,50);
            printf("QUE LE MEILLEUR GAGNE ^^\n");
            system("cls");
            // printf(" Ajouter Fonction RESET");
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");
            break;

        case 2 :
            // Ajouter fonction sauvegarde partie
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");
            break;

        case 3 :

            // AJOUTER PROGRAMME QUI REPREND UNE ANCIENNE PARTIE
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");
            break;

        case 4 :

            fichier_regles = fopen("reglesDuJeu.txt", "r");
            couleur(12, 0);
            printf("Appuyez sur [ECHAP] pour revenir au menu");
            scanf("%c", &echap);
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
                couleur(12, 0);
                printf("Appuyez sur [ECHAP] pour revenir au menu");
                scanf("%c", &echap);
                do {

                couleur(15, 0);
                gotoligcol(10,45);
                printf("La team est constituee de : \n");
                gotoligcol(12,45);
                printf("Yohan MARCEL \n");
                gotoligcol(13,45);
                printf("Sarah BLIN \n");
                gotoligcol(14,45);
                printf("Clement POMPEI \n");
                gotoligcol(15,45);
                couleur(10, 0);
                break;
                } while (echap != '27');

        case 6 :

                exit(0);
     }

}

int main()
{
    affichage_Menu();
}


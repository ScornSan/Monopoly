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

/// FONCTION AFFICHAGE DU MENU

void affichage_Menu ()
{
    int choix;
    char echap;
    gotoligcol(0,50);
    couleur(12, 0);
    printf("=======================\n");
    gotoligcol(1,52);
    couleur(15, 0);
    printf("   MENU MONOPOLY  \n");
    gotoligcol(2,50);
    couleur(12, 0);
    printf("=======================\n");
    couleur(15, 0);
    gotoligcol(5,40);
    printf("1- Lancer une nouvelle partie \n");
    gotoligcol(6,40);
    printf("2- Sauvegarder la partie en cours\n");
    gotoligcol(7,40);
    printf("3- Charger une ancienne partie \n");
    gotoligcol(8,40);
    printf("4- Afficher les regles \n");
    gotoligcol(9,40);
    printf("5- Afficher le nom des membres de l equipe du projet \n");
    gotoligcol(10,40);
    printf("6- Quitter\n");
    gotoligcol(12,40);
    couleur(12, 0);
    printf(">>>>\n");
    gotoligcol(12,45);

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
             printf(" Ajouter Fonction RESET");
             break;

        case 2 :
            printf("Ajouter fonction sauvegarde partie");
            break;

        case 3 :
            // fonction qui charge une autre partie
            break;

        case 4 :
            // print les règles
            break;

        case 5 :
            couleur(15, 0);
            gotoligcol(10,45);
            printf("La team est constituee de : \n");
            gotoligcol(11,45);
            printf("Yohan MARCEL \n");
            gotoligcol(12,45);
            printf("Sarah BLIN \n");
            gotoligcol(13,45);
            printf("Clement POMPEI \n");
            gotoligcol(14,45);
            printf("Benjamin GENDRY \n");
            break;




     }

}





int main()
{
    affichage_Menu();
}

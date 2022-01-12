#include "Structures/structure_joueur.h"
#include "Affichage_plateau/affichage_plateau.h"

void affichage_Menu(int pouvoirsauv, int nombre_de_joueurs, t_joueur joueur_x[], t_carte cartes[][3], int id_max_cartes[])
{
    int keych;
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    FILE * fichier_regles; // pointeur sur le fichier qui contient les règles
    char choix[150]; // On prévoit que l'utilisateur puisse taper "1z" par exemple    int repere[4];
    int choixsauv = 0;
    int repere[4];
    int choixcharge = 0;
    /// AJOUTER BLINDAGE CLEMENT

    do
    {
        system("cls");
        affichage_choix();
        gotoligcol(16,70);
        printf("Entrez votre selection : ");
        fgets(choix,sizeof(choix),stdin);
        char *p=strchr(choix,'\n');
        if(p)
            *p=0;
    }
    while (strlen(choix) != 1 && *choix != 1 && *choix != 2 && *choix != 3 && *choix != 4 && *choix != 5 && *choix != 6);


    system("cls");

    // do
    // {


    switch(*choix-'0')
    {
    case 1 :

        system("cls");
        fflush(stdin);
        system("cls");
        partie_en_cours(pouvoirsauv, nombre_de_joueurs, joueur_x, cartes, id_max_cartes);

        /// AJOUTER FONCTION NOUVELLE PARTIE
        break;

    case 2 :
        // Sauvegarde d'une partie (2 Emplacements)
        printf("%d", pouvoirsauv);
        if (pouvoirsauv == 0) // Verifier si une partie a été joué car on en peu pas sauvegarder à peine arrivé !
        {
            printf("Impossible ! Aucune partie n'est en cours !\n");
            printf("-> Redirection vers le menu... ");
        }
        if (pouvoirsauv == 1)
        {
            // Ajout (Clément)
            gotoligcol(16,70);
            printf("Partie en cours de sauvegarde...\n");
            sauvegardeclassique(nombre_de_joueurs, joueur_x, cartes, id_max_cartes);
            printf("Sauvegarde reussie!\n");
            printf("-> Redirection vers le menu... ");
        }
        sleep(2);
        break;

    case 3 :
        // Charge de partie
        fflush(stdin);
        printf("Chargement de la partie precedente... \n");
        Color(12, 0);
        chargerpartie1(nombre_de_joueurs, joueur_x, cartes, id_max_cartes);
        sleep(2);
        break;

    case 4 :
        fflush(stdin);
        fichier_regles = fopen("Menu/reglesDuJeu.txt", "r");
        Color(12, 0);
        printf("Appuyer sur [M] pour revenir au menu ");

        Color(15, 0);
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
        Color(12, 0);
        printf("Appuyer sur [M] pour revenir au menu ");
        Color(15, 0);
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
        Color(10, 0);
        break;

    case 6 :
        exit(0);
    }
    keych = getch();
    echap(keych, pouvoirsauv, nombre_de_joueurs, joueur_x, cartes, id_max_cartes);
}


int main()
{
    int pouvoirsauv = 0;
    int nombre_de_joueurs = 0;
    int id_max_carte[25];
    t_joueur joueur_x[4];
    t_carte cartes[8][3];
    affichage_Menu(pouvoirsauv, nombre_de_joueurs, joueur_x, cartes, id_max_carte);
    return 0;
}

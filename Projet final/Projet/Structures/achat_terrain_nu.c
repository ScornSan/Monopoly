#include "structure_joueur.h"

void achat_terrain_nu(t_joueur pion_joueur[], int id_joueurs_v1)
{
    t_carte terrain[GROUPES_CARTES][3];
    switch (pion_joueur[id_joueurs_v1].position)
    {
        // Chaque cas correspond à l'indice de la position du joueur, dans le tableau correspondant au plateau
        case 1:
            printf("Vous etes dans la %s\n", terrain[0][0].nom[20]);
            if (terrain[0][0].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][0].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][0].prix_achat;
                }

            }
        case 3:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 4:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 6:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 8:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 9:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 10:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 11:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 13:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 15:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 16:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 17:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 18:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 20:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 22:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 23:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 24:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 25:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }

            }
        case 27:
            printf("Vous etes dans la %s\n", terrain[0][1].nom[20]);
            if (terrain[0][1].prop_achete == false)
            {
                printf("Voulez-vous acheter ce terrain ?\n"
                        "Appuyez sur ENTRER pour acheter le terrain, ou entrez une autre touche pour ne rien faire");
                if (getch() == 13) // 13 est le numéro ascii pour retour charriot, ou ENTER
                {
                    terrain[0][1].prop_achete = true;
                    pion_joueur[id_joueurs_v1].argent = pion_joueur[id_joueurs_v1].argent - terrain[0][1].prix_achat;
                }
            }
    }
}

#include "affichage_plateau.h"


void sepa_lignes()
{
    /// sepa  extérieurs premiere ligne

    int ligne = premiere_ligne;
    for (int z = 0; z < 2; z++)
    {
        for (int i = 0; i<nombre_lignes_a_faire; i++){
            int col = 1;
            for (int j = 0; j<jusque_repetition_colonne; j++)
                {
                    Color(9,15);
                    gotoligcol(ligne,col);
                    col++;
                    printf("%c", 0xCD);
                }
            ligne = ligne + hauteur_case;
        }
        ligne = ligne +25;
    }

    /// Sepa extérieurs deuxieme ligne

    ligne = troisieme_ligne;
    for (int i = 0; i<hauteur_case; i++){
        int col = 1;
        for (int z = 0; z < 2; z++)
        {
            for (int j = 0; j< largeur_case; j++)
                {
                    Color(9,15);
                    gotoligcol(ligne,col);
                    col++;
                    printf("%c", 0xCD);
                }
            col = col +78;
        }
        ligne = ligne + hauteur_case;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "echap.h"

void echap ()
{
    if ( getch() == 27)
    {
        fflush(stdin);
        system("cls");
        affichage_Menu();
    }
}

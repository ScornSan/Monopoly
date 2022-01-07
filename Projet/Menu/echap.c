#include <stdio.h>
#include <stdlib.h>
#include "echap.h"

void echap ()
{
    if ( getch() == 'M' || getch() == 'm')
    {
        fflush(stdin);
        system("cls");
        affichage_Menu();
    }
    fflush(stdin);
}

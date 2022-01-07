#include <stdio.h>
#include <stdlib.h>
#include "echap.h"
#include <stdbool.h>

void echap (appel_menu)
{
    if ( getch() == 'M' || getch() == 'm')
    {
        fflush(stdin);
        system("cls");
        affichage_Menu(appel_menu);
    }
    fflush(stdin);
}

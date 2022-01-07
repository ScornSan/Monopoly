#include <stdio.h>
#include <stdlib.h>
#include "echap.h"
#include <stdbool.h>

void echap()
{
    int key = getch();
    while(key == 'M' || key == 'm')
    {
        system("cls");
        affichage_Menu();
    }
}

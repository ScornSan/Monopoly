#include "affichage.h"

void gotoligcol(int lig, int col)
{
COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

void deplacement_pion_graph(int a, int b)
{
    for (int i = 0; i <= (a + b); i++)
    {

        gotoligcol(10, i-1);
        printf(" ");
        gotoligcol(10, i);
        printf("a");
        usleep(300000);
    }
    return 0;
}



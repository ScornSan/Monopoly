#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoligcol(int lig, int col)
{
COORD mycoord;

mycoord.X = col;

mycoord.Y = lig;

SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

int main()
{
    printf("Helloworld");
    for (int i = 0; i < 32; i++)
    {

        gotoligcol(10, i-1);
        printf(" ");
        gotoligcol(10, i);
        printf("a");
        sleep(1);
    }
    return 0;
}

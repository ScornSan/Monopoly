#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0;
    int b = 0;
    FILE* sauvegarde = NULL;
    sauvegarde = fopen("./sauvegarde.txt", "r"); // ouvre le fichier monfichier.txt se trouvant à côté de l'exécutable
    fscanf(sauvegarde, "%d", &a);
    fscanf(sauvegarde, "%d", &b);
    printf("%d", a);
    printf("\n");
    printf("%d", b);
    fclose(sauvegarde); // le pointeur contient encore l'adresse après !
    sauvegarde = NULL;
}

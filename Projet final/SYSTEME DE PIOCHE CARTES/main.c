#include "bibli1.h"

int main()
{
   int taille = 16;
   int tabchance[taille];
   int tabcommu[taille];

   srand(time(NULL));
   remplissage(tabchance, taille);
   melangeurCarte(tabchance, taille);
   affichage(tabchance, taille);

   printf("\n");

   remplissage(tabcommu, taille);
   melangeurCarte(tabcommu, taille);
   affichage(tabcommu, taille);

   printf("\n\n");

   // Pioche 1 !

   // Donc icifaut placer dans une boucle qui dit : si le perso est en case chance ou commu, executer 1 pioche

   pioche(tabchance, taille);
   affichage(tabchance, taille);

   printf("\n");

   pioche(tabchance, taille);
   affichage(tabchance, taille);


   return 0;
}

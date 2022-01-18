#include <stdio.h>
int main()
{
   int korkeus = 5;
   int leveys = 7;
   int piiri = (korkeus + leveys)*2;
   int alue = korkeus * leveys;
   printf("piiri: %d \n", piiri);
   printf("alue: %d",alue);
   return 0;
}
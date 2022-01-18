#include <stdio.h>

void hello(int y){
   if (y % 400 == 0) {
      printf("is a leap year.");
   }
   else if (y % 100 == 0) {
      printf("is not a leap year.");
   }
   else if (y % 4 == 0) {
      printf("is a leap year.");
   }
   else {
      printf("is not a leap year.");
   }
}

int main() {
   int year;
   printf("Give year: ");
   scanf("%d", &year);
   hello(year);
   return 0;
}
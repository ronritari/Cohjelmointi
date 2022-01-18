#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND -20
#define MAX_RAND 40



int main (void){
    int x;

    x = hello();
    printf("Returned random value is %d",x);
}

int hello (void){
    srand(time(NULL));

    int y=rand() %MAX_RAND +MIN_RAND;
    return y;
}
    
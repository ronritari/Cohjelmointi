#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND -40
#define MAX_RAND 40
#define ARRAY_SIZE 15

int main (void){
    int array[ARRAY_SIZE];
    srand(time(NULL));

    printf("Array of size 15 filled with random numbers (between -40 ... 40) is:\n");

    for(int i=0;i<ARRAY_SIZE;i++){
        //srand(time(NULL));
        int a;
        a = rand() %(MAX_RAND*2) MIN_RAND;
        array[i]=a;
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        printf("%d, ",array[i]);
    }
}
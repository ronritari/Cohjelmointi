#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND 10
#define MAX_RAND 40
#define ARRAY_SIZE 20

int main (void){
    int array[ARRAY_SIZE];
    int reverse[ARRAY_SIZE];
    srand(time(NULL));

    printf("Array of random numbers is: ");

    for(int i=0;i<ARRAY_SIZE;i++){
        //srand(time(NULL));
        int a;
        a = rand() %(MAX_RAND-10) + MIN_RAND;
        array[i]=a;
    }

    for(int i=0;i<ARRAY_SIZE;i++){
        printf("%d, ",array[i]);
    }
    printf("\n");

    int s=0;
    int b;

    for(int i=ARRAY_SIZE;i>-1;i--){
        b=array[i];
        reverse[s]=b;
        s++;
    }

    printf("Same array in reverse order is: ");
    for(int i=1;i<=ARRAY_SIZE;i++){
        printf("%d, ",reverse[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND -50
#define MAX_RAND 120
#define ARRAY_SIZE 15

int main (void){
    int array[ARRAY_SIZE]={0};
    int even[ARRAY_SIZE]={0};
    int odd[ARRAY_SIZE]={0};
    
    srand(time(NULL));

   

    for(int i=0;i<ARRAY_SIZE;i++){
        int a;
        a = rand() %MAX_RAND MIN_RAND;

        //printf("%d",a);
        array[i]=a;

        if(a % 2 == 0){
            even[i]=a;
        }else{
            odd[i]=a;
        }
    }

    printf("all numbers are:\n");
    for(int i=0;i<11;i++){
        printf("%d, " ,array[i]);
    }
    printf("\n");

    printf("all even numbers are:\n ");
    for(int i=0;i<11;i++){
        if(even[i]==0){

        }else{
            printf("%d, " ,even[i]);
        }
    }
    printf("\n");

    printf("all odd numbers are:\n ");
    for(int i=0;i<11;i++){
        if(odd[i]==0){

        }else{
            printf("%d, " ,odd[i]);
        }
        
    }

}
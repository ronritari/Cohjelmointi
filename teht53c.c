#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND 50
#define MAX_RAND 100
#define ARRAY_SIZE 20

int sort_array(int array[]){
    int temp = 0;
    int length = ARRAY_SIZE ; 

    for (int i = 0; i < length; i++) {     
        for (int j = i+1; j < length; j++) {     
           if(array[i] > array[j]) {    
               temp = array[i];    
               array[i] = array[j];    
               array[j] = temp;    
           }     
        }     
    }  
    /*for(int i=0;i<ARRAY_SIZE;i++){
        printf("%d, ",array[i]);
    }*/
    return array;
}

int main (void){
    int array[ARRAY_SIZE];
    srand(time(NULL));

    for(int i=0;i<ARRAY_SIZE;i++){
        //srand(time(NULL));
        int a;
        a = rand() %MAX_RAND-MIN_RAND;
        array[i]=a;
    }

    printf("original array is: ");
    for(int i=0;i<ARRAY_SIZE;i++){
        printf("%d, ",array[i]);
    }

    printf("\nsorted array is: ");
    
    
    int *array2;
    array2=sort_array(array);
    for(int i=0;i<ARRAY_SIZE;i++){
        printf("%d, ",array2[i]);
    }

    return 0;

}
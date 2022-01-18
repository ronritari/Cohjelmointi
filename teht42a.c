#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    int ARRAY_SIZE=20;
    int MAX_RAND=100;
    int MIN_RAND=1;
    int array[ARRAY_SIZE];

    srand(time(NULL));
    
    //fill the array with random numbers
    for(int i=0;i<=ARRAY_SIZE;i++){
        int a;
        a = rand() %MAX_RAND +MIN_RAND;
        array[i]=a;
    }

    //chek every index for the biggest number store in int
    int big=0;
    for(int i=0;i<=ARRAY_SIZE;i++){
        if(array[i]>big){
            big=array[i];
        }
    }
    //chek smallest number store in int
    int small=100;
    for(int i=0;i<=ARRAY_SIZE;i++){
        if(array[i]<small){
            small=array[i];
        }
    }
    //print at end
    printf("Content of array is [ ");
    for(int i=0;i<=ARRAY_SIZE;i++){
        printf("%d, ",array[i]);
    }
    printf(" ]\n");

    printf("and the biggest number was %d and smallest was %d\n\n",big,small);

    //printtaa kymmenet 
    printf("    ");
    int lol=0;
    int bruh=1;
    for(int i=0; i<=big; i++){
      
        if(lol==9){
            printf("%d",bruh);
            lol=0;
            bruh++;
        }else{
            printf(" ");
            lol++;
        }

    }
    printf("\n");
    int luku=0;
    printf("   ");
    //printtaa taulun toho ylös dafuq
    for(int i=0; i<=big; i++){
        
        printf("%d", luku);
        if(luku==9){
            luku=0;
        }else{
            luku++;
        }

    }

    printf("\n   ");
    //printtaa viivan sen alle dafuq
    int vika=big;
    for(int i=0; i<=big; i++){
        
        printf("-", luku);
        if(i==vika){
            printf(">");
        }

    }

    printf("\n");
    //print stars
    for(int i=0; i<=ARRAY_SIZE;i++){
        if(i<10){
            printf(" %d: ",i);
        }else{
            printf("%d: ",i);
        }
        
        for(int k=1; k<=array[i];k++){
            printf("*");
        }

        for(int k=array[i];k<=big;k++){
            printf(" ");
        }
        //if toi num pienempi ku 10
        if(array[i]<10){
            printf("(  %d)",array[i]);
        }else{
            printf("( %d)",array[i]);
        }
       // printf("( %d)",array[i]);
        printf("\n");
       
    }


}
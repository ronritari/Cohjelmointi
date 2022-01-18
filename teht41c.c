#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND 10
#define MAX_RAND 11
#define ARRAY_SIZE 1000

int main (void){
    int array[10]={0};
    
    srand(time(NULL));

   

    for(int i=0;i<ARRAY_SIZE;i++){
        int a;
        a = rand() %MAX_RAND;
        
        //printf("%d",a);
        if(a==0){
            array[0]++;
        }if(a==1){
            array[1]++;
        }if(a==2){
            array[2]++;
        }if(a==3){
            array[3]++;
        }if(a==4){
            array[4]++;
        }if(a==5){
            array[5]++;
        }if(a==6){
            array[6]++;
        }if(a==7){
            array[7]++;
        }if(a==8){
            array[8]++;
        }if(a==9){
            array[9]++;
        }if(a==10){
            array[10]++;
        }
    }

    for(int i=0;i<11;i++){
        printf("number %d ocurred %d times \n",i ,array[i]);
    }
    printf("\n");

}
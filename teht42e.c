#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (void){
    srand(time(NULL));
    int ARRAY_SIZE=110;
    int MAX_RAND=99;
    int MIN_RAND=1;
    int array[ARRAY_SIZE];
    int arpa=0;
    float apu[ARRAY_SIZE];

    while(arpa<21){
        int a;
        a = rand() %MAX_RAND;
        if(array[a]==0){
            array[a]=1;
            arpa++;
        }
        
    }
    float k=-1;
    
    for(int i=0;i<ARRAY_SIZE;i++){
        
        apu[i]=k;
        //printf("%.1f\n",(float)apu[i]);
        k=k+0.1;

    }
    
    printf("Content of array is:  ");
    for(int i=0; i<ARRAY_SIZE;i++){
        if(array[i]==1){
            printf("%.1f, ",(float)apu[i]);
            
            arpa--;
        }
    }
}
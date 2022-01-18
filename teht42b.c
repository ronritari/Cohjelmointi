#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    srand(time(NULL));
    int ARRAY_SIZE=39;
    int MAX_RAND=39;
    int MIN_RAND=1;
    int array[ARRAY_SIZE];
    int arpa=0;
    int voitto[8];

    while(arpa<7){
        int a;
        a = rand() %MAX_RAND+MIN_RAND;
        if(array[a]==0){
            array[a]=1;
            arpa++;
        }
        
    }
    int k=0;
    
    
    for(int i=0; i<ARRAY_SIZE;i++){
        if(array[i]==1){
            voitto[k]=i;
            k++;
            arpa--;
        }
    }

    printf("User played numbers: ");
    for(int i=0;i<7;i++){
        printf("%d, ",voitto[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define MIN_RAND 1
#define MAX_RAND 100
#define ARRAY_SIZE 20


int main(void){
int array[20]={0};

srand(time(NULL));

for(int i=0; i<ARRAY_SIZE; i++){

  int a;
  a=rand()%MAX_RAND + MIN_RAND;

array[i]=a;
  
}

printf("content of array is[");

for(int i=0; i<ARRAY_SIZE; i++){

  printf("%d,", array[i]);
}
  printf("]\n");

  int Suurin = 0;
  
  for(int i=0; i<ARRAY_SIZE; i++){

    if(array[i]>Suurin){
      Suurin = array[i];
    }
  }
     //printf("%d", Suurin);

    int Pienin = 100;

     for(int i=0; i<ARRAY_SIZE; i++){
      
      if(array[i]<Pienin){
        Pienin = array[i];
      }

     }

     printf("and the biggest number was %d and smallest was %d\n\n",  Suurin, Pienin);
     int val = 0; 
  int kymmenet = 1;
  printf("   ");
  printf(" "); 
  for(int i=0; i< Suurin; i++){

    if(val==9){

      printf("%d", kymmenet); 

      val=0; 
      kymmenet++;


    }else{
        
        printf(" "); 
         val++;
        
    }
  }
  printf("\n"); 
  printf("   ");

int luku = 0; 

  for(int i=0; i<= Suurin; i++){

  printf("%d", luku);

  if(luku==9){
    luku=0;

  }else {
    luku++;
  }
  }

   printf("\n");
   printf("   ");

  for(int i=0; i<= Suurin; i++){

    printf("-");

    
  }

    printf(">");
  

    printf("\n");

  for(int i=0; i<ARRAY_SIZE;i++){
        if(i<10){
            printf(" %d: ",i);
        }else{
            printf("%d: ",i);
        }
        
        for(int k=1; k<=array[i];k++){
            printf("*");
        }

        for(int k=array[i];k<=Suurin;k++){
            printf(" ");
        }
        
        if(array[i]<10){
            printf("(  %d)",array[i]);
        }else{
            printf("( %d)",array[i]);
        }
       
        printf("\n");
       
    }
}
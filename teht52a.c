#include <stdio.h>

int hello(){
    int i=0;
    int a;
    while (i!=1){
    scanf("%d",&a);
    
        if(a>20&&a<70){
            i++;
        }else{
            printf("Number was not in range (20-70):");
        }
    }

    
    return a;
}


void main(void)
{
    printf("Give number between 20 and 70:");
    int b=hello();
    printf("\nUser given number was %d",b);
}
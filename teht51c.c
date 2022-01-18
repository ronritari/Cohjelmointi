#include <stdio.h>

int main(void){
    printf("give number 1: ");
    int a,b;
    scanf("%d",&a);
    printf("give number 2: ");
    scanf("%d",&b);
    hello(a,b);
    
}

void hello (int a, int b){
    printf("User entered numbers %d and %d.\n",a,b);
    if(a<b){
        printf("bigger number is %d ",b);
    }else{
        printf("bigger number is %d ",a);
    }
    float kes=(float)(a+b)/2;
    printf("and avarage is %.1f ",kes);
}
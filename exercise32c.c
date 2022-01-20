#include <stdio.h>
int main (void)
{
    printf("Enter 10 numbers\n");
    int a=0;
    int array[10];

    
    for(int i=0;i<=9;i++){
        float d;
        printf("%d. ",i);
        scanf("%f",&d);
        a=a+d;
        array[i] = d;
        printf("\n");
    }

    float tulos = a / 10;
    printf("The mean value of numbers [ ");
    for(int i=0;i<9;i++){
        printf("%d,",array[i]);
    }
    printf("%d ] is %.2f ",array[9], tulos);
}
#include <stdio.h>
int main (void)
{
    printf("Enter 10 numbers\n");
    int a=0;
    int array[10];

    
    for(int i=1;i<=10;i++){
        float d;
        printf("%d. ",i);
        scanf("%f",&d);
        a=a+d;
        array[i] = d;
        printf("\n");
    }

    float tulos = a / 10;
    printf("The mean value of numbers ");
    for(int i=0;i<=10;i++){
        printf("%d,",array[i]);
    }
    printf(" is %.2f ", tulos);
}
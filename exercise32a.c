#include <stdio.h>
int main (void)
{
    int a;
    printf("Give me number: \n");
    scanf("%d",&a);
    printf("The multiplication table for %d is: \n",4);

    for(int i=0;i<=10;i++){
        int b= i*a;
        printf("%d * %d = %d \n",i,a,b);
    }
}
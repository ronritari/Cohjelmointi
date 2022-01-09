#include <stdio.h>
int main()
{
    int a;
    int b;

    printf("Give number 1");
    scanf("%d",&a);
    printf("Give number 2");
    scanf("%d",&b);

    if(a<b){
        printf("User did input numbers %d and %d and the bigger one is %d",a,b,b);
    }else{
        printf("User did input numbers %d and %d and the bigger one is %d",a,b,a);
    }
    
}
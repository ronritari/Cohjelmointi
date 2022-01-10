#include <stdio.h>
int main()
{
    char a;

    printf("Give me a letter: ");
    scanf("%c",&a);

    if(a >= 65 && a<= 90){
        printf("Letter %c is a Capital letter",a);
    }else{
        printf("Letter %c is not a Capital letter",a);
    }
    
}
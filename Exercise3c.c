#include <stdio.h>

int main()
{
    char a;

    printf("Give me a letter: ");
    scanf("%c",&a);

    if(a >= 65 && a<= 90){
        printf("Letter %c is a Capital letter",a);
    }else if(a >= 97 && a<= 122){
        printf("Letter %c is a lowecase letter",a);
    }else{
        printf("Letter %c is a special character",a);
    }
    
}
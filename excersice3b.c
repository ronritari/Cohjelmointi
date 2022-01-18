#include <stdio.h>

int main(void){
    char c;
    
    printf("give me a letter: ");
    scanf("%c", &c);
     
if(c >= 'A' && c <= 'Z')
        printf("character %c is capital", c);
        
else if(c >= 'a' && c <= 'z')
        
    printf("character %c is lowercase");
else
printf("error");
     return 0;
    
    
    
    
}
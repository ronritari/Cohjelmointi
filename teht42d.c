#include <stdio.h>

int main(void){

    char org[30];
    int i;
    

    printf("Give String: ");
    scanf("%s",&org);

    //check length
    while(org[i]!='\0') {
        //printf("%c",org[i]);
        i++;
            
    }

    printf("Length of the string is: %d\n",i);
    //RESET i
    i=0;

    printf("The copied string is: ");

    while(org[i]!='\0') {
        printf("%c",org[i]);
        i++;
            
    }
    
}
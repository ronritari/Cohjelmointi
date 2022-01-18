#include <stdio.h>
#include <string.h>

int main(void){
    char org[30];
    int length;
    

    printf("Give String: ");

    fgets(org,30,stdin);
    length=strlen(org)-1;

    printf("Length of the string is: %d\n",length);
    //ilmoittaa a muuttujan virheestä, mutta toimii normaalisti
    int a=length;
    char new[a];
    strcpy(new,org);

    printf("The copied string is: %s",new);


}
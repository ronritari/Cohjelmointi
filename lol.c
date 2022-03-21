#include <stdio.h>
int main (void){
    char s[]="this is a test text";
    capitalizeWords(s);
    printf("<%s>",s);
}


void capitalizeWords(char s[]){

    for(int i=0; s[i]!='\0'; i++){

        if(s[i]== ' '){
            s[i+1]=s[i+1]-32;
        }else if (i==0){
            s[i]=s[i]-32; 
        }
    }
}
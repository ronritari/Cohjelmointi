#include <stdio.h>

int main(void){
    printf("This text is printed in main");
    hello();
    printf("\nAnd back again in main");
}

void hello (void){
    printf("\nHi, A am a function");
}


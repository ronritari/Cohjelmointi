#include <stdio.h>

int main(void){
    printf("give number: ");
    int a;
    scanf("%d",&a);
    hello(a);
    
}

void hello (int a){
    for(int i=0;i<a;i++){
        printf("cock-a-doodle-doo\n");
    }
    
}
#include <stdio.h>
int main(void)
{
    int a;
    printf("Input rows:\n");
    scanf("%d",&a);
    int c=(a*2)-2;
    
    for(int i=1;i<=a;i++){
        for(int b=0;b<i;b++){
            printf("%d",i);
            
            
        }
        for (int f=0; f<c; f++){
             if(c==1){

             }else
                 printf(" ");
            }
            c=c-2;
            for(int b=0;b<i;b++){
            printf("%d",i);
            }

        printf("\n");
    }
}
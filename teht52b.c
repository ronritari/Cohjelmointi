#include <stdio.h>
#define MIN_V 0
#define MAX_V 100
#define MIN_R 1
#define MAX_R 65
int hello(int min,int max){
    int i=0;
    int a;
    while (i!=1){
    scanf("%d",&a);
    
        if(a>min&&a<max){
            i++;
        }else{
            printf("Number was not in range (%d-%d):",min,max);
        }
    }

    
    return a;
}


void main(void)
{
    printf("Give Voltage between 0 and 100: ");
    int b=hello(MIN_V,MAX_V);
    printf("Give Resistance between 1 and 65: ");
    int c=hello(MIN_R,MAX_R);
    float amp=(float)b/c;
    float w=(float)amp*b;
    printf("Power consumption in %d ohm resistance with %d V voltage is %.1f W and current is %.1f A",c,b,w,amp);
}
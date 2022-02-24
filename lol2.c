#include <stdio.h>
#include <math.h>

int main(void)
{
    //celsius ja ms
    //35.74 + 0.6215 × T - 35.75 × V 0.16 + 0.4275 × T × V 0.16
    float lampo;
    float potenssi=0.16;
    float nopeus;
    //float result = pow(nopeus, potenssi);
    
    //printf("%f",result);
    
    printf("Give temperature in Celsius:");
    scanf("%f",&lampo);
    printf("Give Wind speed in m/s");
    scanf("%f",&nopeus);
    printf("Feels like:");
    float result = pow(nopeus*3.6, potenssi);

    float f= 13.12   + (0.6215 *lampo) - (11.37 * result )+ (0.3965 * lampo *result) ;
    printf("%f",f);
}


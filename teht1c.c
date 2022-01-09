#include <stdio.h>
int main()
{
    printf("anna korkeus ja paina enter\n");
    float korkeus;
    float leveys;
    scanf("%f",&korkeus);
    printf("anna leveys ja paina enter\n");
    scanf("%f",&leveys);
    float piiri = (korkeus + leveys)*2;
    printf("piiri: %.2f \n", piiri);
    float alue = korkeus * leveys;
    printf("%.2f",alue);
    return 0;
}
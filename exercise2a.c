#include <stdio.h>
int main()
{
    char nimi[30]= "Charley Brown";
    char sex ='M';
    int ika = 21;
    float kenka=44;
    float pankki=34.34;
    char osote[30]="Willowstreet";
    char puh[15]="050-234243242";

    printf("Name: %s\n",nimi);
    printf("Gender: %c\n",sex);
    printf("Address: %s\n", osote);
    printf("phone: %s\n",puh);
    printf("Age: %d\n",ika);
    printf("Bank Balance: %.2f\n",pankki);
    printf("Shoe Size: %.1f\n",kenka);

    return 0;
}
#include <stdio.h>
int main()
{
    char etunimi[30];
    char sukunimi[30];
    char sex[2];
    int ika;
    float kenka;
    float pankki;
    char osote[30];
    char puh[15];

    printf("write first and lastname then press enter\n");
    scanf("%s %s",&etunimi, &sukunimi);
    printf("write your gender M or F then press enter\n");
    scanf("%s",&sex);
    printf("write your age then press enter\n");
    scanf("%d",&ika);
    printf("write your shoe size then press enter\n");
    scanf("%f",&kenka);
    printf("write your bank balance then press enter\n");
    scanf("%f",&pankki);
    printf("write your address then press enter\n");
    scanf("%s",&osote);
    printf("write your phonenumber then press enter\n");
    scanf("%s",&puh);

    

    printf("Name: %s %s \n",etunimi, sukunimi);
    printf("Gender: %s \n",sex);
    printf("Address: %s \n", osote);
    printf("phone: %s \n",puh);
    printf("Age: %d \n",ika);
    printf("Bank Balance: %.2f \n",pankki);
    printf("Shoe Size: %.2f \n",kenka);

    return 0;
}
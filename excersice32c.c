#include <stdio.h>
int main(void){
//read 10 numbers from a user  
int a;
int apu;
int array[10];
printf("Enter 10 numbers\n"); 
for(int i=1; i<=10; i++){
    printf("%d.",i);
    scanf("%d",&a);
    apu= apu+a;
    array[i]=a;

}
float divide = apu/10;
printf("The mean value of numbers "); 
for(int i=1;i<=10;i++){
        printf("%d,",array[i]);
    }
printf("is %.2f", divide);






}
 
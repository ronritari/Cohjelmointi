#include <stdio.h>
int main(void){
int num, count;
//printf("Multiplication table for %d is:\n");
for (int i=0; i<=10; i++){
    printf("%d: n kertotaulu\n",i);
    for (count = 0; count <= 10; count++){
        printf("%d * %d = %d\n", i, count, (i*count));
    }
    printf("\n");
}
 return 0; 
}
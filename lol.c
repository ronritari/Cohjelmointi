#include <stdio.h>
int main(void)
{
  int tahti;
  scanf("%d",&tahti);
  int rivi=tahti;
  for(int k=0;k<tahti;k++){
    for(int i=0;i<rivi;i++){
      printf(" ");
    }
    for(int t=0;t<tahti;t++){
    printf("*");
    }
    printf("\n");
    rivi--;
  }
}



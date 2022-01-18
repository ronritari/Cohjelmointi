#include <stdio.h>

float calc_average(int f, int s){
    int summa=f+s;
    float keski=(float)summa/2;
    return keski;
}


int main(void)
{
int first, second;
float average;

  printf("Give two numbers separated by comma: ");
  scanf("%d, %d",&first, &second);
  average = calc_average(first, second);

  printf("Average of %d and %d is %.2f\n",first, second, average);

}



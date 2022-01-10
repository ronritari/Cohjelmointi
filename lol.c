#include <stdio.h>
int main(void)
{
  printf("Input rows: \n");
  int out, in;
  int row_size;
  scanf("%d", &row_size);
  int print_control_x = 1;
  int print_control_y = row_size * 2 - 1;
  int x=row_size;
  int y=row_size;
  
  for (out = row_size; out >= 1; out--)
  {
    printf(" ");
    for (in = 1; in <= row_size * 2; in++)
    {       
      
      if (out==1){
        
      }
      else if (in == print_control_x || in == print_control_y)
      {
        printf("%d", print_control_x);
      }
      else
      {
        printf(" ");
      }
    }
    print_control_x++;
    print_control_y--;
    if(out==1){

    }else{
      printf("\n");
    }
    
  }
  for (out = 1; out <= row_size; out++)
  {
    if(out==1){

    }else{
      printf(" ");
    }
    
    for (in = 1; in <= row_size * 2; in++)
    {
      if (in == x|| in == y)
      {
        printf("%d",x);
      }
      else
      {
        printf(" ");
      }
    }
    x--;
    y++;
    printf("\n");
  }


}





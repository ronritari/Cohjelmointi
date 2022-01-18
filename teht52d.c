#include <stdio.h>

int days_in_month(int d){
    int array[4]={30,31,28};
    if(d==1||d==3||d==5||d==7||d==8||d==10||d==12){
        return array[1];
    }else if(d==4||d==6||d==9||d==11){
        return array[0];
    }else if(d==2){
        return array[2];
    }else{
        
    }
}
int main() {
   int month;
   printf("Give month: ");
   scanf("%d", &month);
   int d=days_in_month(month);
   printf("There are %d days in ",d);
   switch (month)
   {
   case 1:
       printf("january");
       break;
    case 2:
        printf("february");
        break;
    case 3:
       printf("march");
       break;
    case 4:
        printf("april");
        break;
    case 5:
       printf("may");
       break;
    case 6:
        printf("june");
        break;
    case 7:
       printf("july");
       break;
    case 8:
        printf("august");
        break;
    case 9:
       printf("september");
       break;
    case 10:
        printf("october");
        break; 
    case 11:
       printf("november");
       break;
    case 12:
        printf("december");
        break;       
   default:
       break;
   }


   return 0;
}
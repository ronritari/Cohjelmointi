#include <stdio.h>
int find_position(int a[], int n){
  int k=0;
  for(int i=0; a[i]!=0; i++){
    if(a[i]==n){
      k=i;
      return k;
    }
  }
  return -1;
  /*
  if(k==0){
    return -1;
  }else{
    return k;
  }*/
}
void main(void) {
    int a[]={1,-20,3,4,5,6,7,8,9,0};
    printf(" %d",find_position(a,1));
}







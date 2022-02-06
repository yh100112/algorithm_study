#include<stdio.h>

int main(){
  int i,j,temp;
  int array[10]={1,10,5,8,6,5,4,3,2,9};
  for(i = 0;i < 9; i++){
    j = i;
    while(array[j] > array[j+1]){
      temp = array[j];
      array[j] =  array[j+1];
      array[j+1] = temp;
      j--;
    }
    for(int k = 0; k < 10; k++){
      printf("%d ",array[k]);        
    }
    printf("\n");
  }

}
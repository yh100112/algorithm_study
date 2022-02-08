#include<stdio.h>

int main(){
  int i,j,temp;
  int array[3]={10,5,3};

  for(i = 0;i < 3; i++){
    j = i;
    while( j >= 0 && array[j] > array[j+1]){
      temp = array[j];
      array[j] =  array[j+1];
      array[j+1] = temp;
      j--;
    }
  }

  for(int k = 0; k < 3; k++){
    printf("%d ",array[k]);        
  }
}
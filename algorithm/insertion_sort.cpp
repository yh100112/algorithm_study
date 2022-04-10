#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  int i,j,temp;
  int array[10]={1,10,5,8,7,6,4,3,2,9};

  for(i = 0;i < 9; i++){
    j = i;
    while( j >= 0 && array[j] > array[j+1]){
      swap(array[j],array[j+1]);
      j--;
    }
  }

  for(int k = 0; k < 10; k++){
    printf("%d ",array[k]);        
  }
}
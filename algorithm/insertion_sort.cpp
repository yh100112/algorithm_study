#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  int i,j,temp;
  int array[3]={10,5,3};

  for(i = 0;i < 3; i++){
    j = i;
    while( j >= 0 && array[j] > array[j+1]){
      swap(array[j],array[j+1]);
      j--;
    }
  }

  for(int k = 0; k < 3; k++){
    printf("%d ",array[k]);        
  }
}
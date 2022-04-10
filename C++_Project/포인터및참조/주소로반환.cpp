#include<stdio.h>

int* allocateArray(int size){
  return new int[size];
}

int main(){
  int* array = allocateArray(25);
  delete[] array;
  
}
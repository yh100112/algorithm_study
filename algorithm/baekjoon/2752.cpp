#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  int i,j,temp;
  int data[3];

  for(i = 0; i < 3; i++){
    scanf("%d",&data[i]);
  }

  for(i=0;i<3;i++){
    j = i;
    while(j >= 0 && data[j] > data[j+1]){
      temp = data[j];
      data[j] = data[j+1];
      data[j+1] = temp;
      j--;
    }
  }

  for(i = 0; i < 3; i++){
    printf("%d ",data[i]);
  }
}
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  int data[1001];

  int i,j,index,number,min;
  scanf("%d",&number);
  for(i=0;i<number;i++){
    scanf("%d",&data[i]);
  }

  for(i=0;i<number;i++){
    min = 1001;
    for(j=i;j<number;j++){
      if(data[j] < min){
        min = data[j];
        index = j;
      }
    }
    swap(data[i],data[index]);
  }

  for(i=0;i<number;i++){
    printf("%d\n",data[i]);
  }
}
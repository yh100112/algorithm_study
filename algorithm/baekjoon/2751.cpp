#include<iostream>
#include<stdio.h>
using namespace std;

void quickSort(int* data, int start, int end){
  if(start >= end) return;

  int left = start;
  int right = end;
  int pivot = (start + end) / 2;
  int temp;

  while(left < right){
    while(data[left] < data[pivot]) left++;
    while(data[right] > data[pivot]) right--;

    if(left <= right){
      temp = data[left];
      data[left] = data[right];
      data[right] = temp;
      left++;
      right--;
    }
  }

  quickSort(data, start, right);
  quickSort(data, left,end);
}

int main(){
  int i,j,n,a;
  scanf("%d",&n);

  int data[n+1];
  for(i=0; i<n; i++){
    scanf("%d",&a);
    data[i] =a;
  }

  quickSort(data,0,n-1);
  for(i=0; i<n; i++){
    printf("%d\n",data[i]);
  }
}


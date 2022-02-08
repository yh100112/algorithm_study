#include<stdio.h>
#include<iostream>
using namespace std;


void quickSort(int* data, int start, int end){
  if(start >= end) return;

  int left = start;
  int right = end;
  int pivot = (start + end) / 2;

  while(left < right){
    while(data[left] < data[pivot]) left++;
    while(data[right] > data[pivot]) right--;

    if(left <= right){
      swap(data[left],data[right]);
      left++;
      right--;
    } 
  }

  quickSort(data, start,right);
  quickSort(data, left,end);
}

int main(){
  int n;
  int i;
  int data[1001];
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&data[i]);
  }

  quickSort(data,0,n-1);
  for(i = 0; i < n; i++){
    printf("%d\n",data[i]);
  }
}
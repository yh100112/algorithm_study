#include<stdio.h>
#include<iostream>
using namespace std;

int data[] = {2,1,6,3,4,5,6,2,1,6,3,4,5,6};

void quickSort(int start, int end){
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
  quickSort(start,right);
  quickSort(left,end);
}

int main(){
  quickSort(0,(sizeof(data) / sizeof(data[0]))-1);
  for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++){
    printf("%d ", data[i]);
  }
}
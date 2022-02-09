#include<stdio.h>
#include<iostream>
using namespace std;

int ppp[] = {2,1,6,3,4,5,6,2,1,6,3,4,5,6};

void quickSort(int start, int end){
  if(start >= end) return;

  int left = start;
  int right = end;
  int pivot = (start + end) / 2;

  while(left < right){
    while(ppp[left] < ppp[pivot]) left++;
    while(ppp[right] > ppp[pivot]) right--;

    if(left <= right){
      swap(ppp[left],ppp[right]);
      left++;
      right--;
    }
  }
  quickSort(start,right);
  quickSort(left,end);
}

int main(){
  quickSort(0,(sizeof(ppp) / sizeof(ppp[0]))-1);
  for(int i = 0; i < sizeof(ppp) / sizeof(ppp[0]); i++){
    printf("%d ", ppp[i]);
  }
}
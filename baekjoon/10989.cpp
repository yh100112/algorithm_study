#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

void quickSort(int* array,int start, int end){
  if(start >= end)  return;

  int left = start;
  int right = end;
  int pivot = (left + right) / 2;

  while(left < right){
    while(array[left] < array[pivot]) left++;
    while(array[right] > array[left]) right--;
  
    if(left <= right){
      swap(array[left],array[right]);
      left++;
      right--;
    }
  }

  quickSort(array, start, right);
  quickSort(array, left, end);
}

int main(){
  int n,i;
  scanf("%d",&n);
  int* array = new int[10000];

  for(i=0; i < n; i++){
    scanf("%d",&array[i]);
  }

  quickSort(array,0,n-1);

  for(i = 0; i < n; i++){
    printf("%d\n",array[i]);
  }

  delete[] array;
}
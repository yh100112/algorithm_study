#include<stdio.h>
#include<iostream>
using namespace std;
  
int array[7] = {1,3,5,7,2,4,6};
int n = 7;
int* array2;

void merge(int start, int end){
  int i = start;
  int mid = (start + end) / 2;
  int j = mid + 1;
  int k = start;

  while(i <= mid && j <= end){
    if(array[i] < array[j]){
      array2[k++] = array[i++];
    }else{
      array2[k++] = array[j++];
    }
  }

  int temp = i > mid ? j : i;
  while(k <= end){
    array2[k++] = array[temp++];
  }

  for(int i = start; i <= end; i++){
    array[i] = array2[i];
  }
}

void partition(int start, int end){
  int mid;
  if(start < end){
    mid = (start + end) / 2;
    partition(start,mid);
    partition(mid+1,end);
    merge(start,end);  
  }
}

int main(){
  int i;
  array2 = new int[n];

  partition(0,n-1);

  for(i=0; i < n; i++){
    printf("%d ", array[i]);
  }

  delete[] array2;
}
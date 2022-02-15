#include<iostream>
#include<stdio.h>

using namespace std;

int n = 7;
int array[7] = {1,9,2,4,5,7,3};
int* arr2;

void merge(int start, int end){
  int i = start;
  int mid = (start + end) / 2;
  int j = mid + 1;
  int k = start;


  while(i <= mid && j <= end){
    if(array[i] < array[j]){
      arr2[k++] = array[i++];
    }else{
      arr2[k++] = array[j++];
    }
  }

  int temp = i > mid ? j : i;
  while(k <= end){
    arr2[k++] = array[temp++];
  }

  for(int a = start; a <= end; a++){
    array[a] = arr2[a];
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

  arr2 = new int[n];
  partition(0,n-1);
  for(int i = 0; i < n;i++){
    printf("%d ",array[i]);
  }
  
  delete[] arr2;
}
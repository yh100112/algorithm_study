#include<iostream>
using namespace std;

int arr[10] = {1,3,5,7,9,2,4,6,8,10};
int* arr2;

void merge(int start, int end){
  int mid = (start + end) / 2;

  int i = start;
  int j = mid + 1;
  int temp = start;

  while(i <= mid && j <= end){
    if(arr[i] <= arr[j]){
      arr2[temp++] = arr[i++];
    }else{
      arr2[temp++] = arr[j++];
    }
  }

  int remain_idx = i > mid ? j : i;
  while(temp <= end){
    arr2[temp++] = arr[remain_idx++];
  }

  for(int i = start; i <= end; i++){
    arr[i] = arr2[i];
  }
}

void mergeSort(int start, int end){
  int mid;
  if(start < end){
    mid = (start + end) / 2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    merge(start,end);
  }
}

int main(){
  arr2 = new int[10];
  mergeSort(0,9);

  for(int i = 0;i < 10; i++){
    printf("%d ",arr[i]);
  }

  delete[] arr2;
}
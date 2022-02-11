#include<stdio.h>
#include<iostream>

using namespace std;

int n = 7;
int a[8] = {-100,1,9,5,4,7,2,8}; 

void heapify(int i){
  int parent = i;
  int child = i * 2;

  if(a[child] < a[child+1]) child++;

  if(a[parent] < a[child]){
    swap(a[parent],a[child]);
    if(child <= n / 2){
      heapify(child);
    }
  }
}

void heapSort(int i){
  
}

int main(){

  //처음에 최대 힙으로 만들기
  for(int i = n / 2; i >= 1; i--){
    heapify(i);
  }

  for(int i = n; i > 0; i--){
    heapSort(i);
  }

  for(int j = 1; j <= n; j++){
    printf("%d ",a[j]);
  }

}
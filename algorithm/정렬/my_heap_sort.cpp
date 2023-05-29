#include<stdio.h>
#include<iostream>

using namespace std;

int n = 7;
int heap[8] = {-100,1,9,5,4,7,2,8}; 

void heapify(int i){
  int parent = i;
  int child = i * 2;

  if(heap[child] < heap[child+1]) child++;

  if(heap[parent] < heap[child]){
    swap(heap[parent],heap[child]);
    if(child <= n / 2){
      heapify(child);
    }
  }
}

void heapSort(int i){
  int root = 1;
  int child = 2;
  swap(heap[root], heap[i]);

  //마지막 노드를 제외하고 최대힙으로 구성
  do{
    child = root * 2;
    if((heap[child] < heap[child + 1]) && (child < i - 1)){
      child++;
    } 

    if(heap[root] < heap[child] && child < i){
      swap(heap[root],heap[child]);
    }

    root = child;
  }while(child < i);
}

int main(){

  //처음에 최대 힙으로 만들기
  for(int i = n / 2; i >= 1; i--){
    heapify(i);
  }

  //힙 정렬 수행
  for(int i = n; i > 0; i--){
    heapSort(i);
    // printf("%d : ",i);
    // for(int j = 1; j <= n; j++){
    //   printf("%d ",heap[j]);
    // }
    // printf("\n");
  }


}
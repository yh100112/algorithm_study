#include<stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

int main(){
  //먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
  for(int i = 1; i < number; i++){
    int c = i; // 자식 인덱스
    do{
      int root = (c - 1) / 2; // 부모
      if(heap[root] < heap[c]){
        int temp = heap[root];
        heap[root] = heap[c];
        heap[c] = temp;
      }
      c = root; //자식의 부모로 올라가서 heapify 수행
    }while(c != 0);
  }

  //크기를 줄여가며 반복적으로 힙을 구성
  for(int i = number - 1; i >= 0; i--){
    //마지막 노드와 루트 노드를 교환
    int temp = heap[0];
    heap[0] = heap[i];
    heap[i] = temp;


    // 마지막 값을 빼고 힙 구조를 만드는 부분
    int root = 0;
    int c = 1;
    do{
      c = 2 * root + 1; // 자식
      
      // 자식 중에 더 큰 값을 찾기 ( i - 1보단 적게)
      if(heap[c] < heap[c+1] && c < i - 1){
        c++;
      }

      //루트보다 자식이 더 크다면 교환
      if(heap[root] < heap[c] && c < i){
        int temp = heap[root];
        heap[root] = heap[c];
        heap[c] = temp;
      }
      root = c;
    }while(c < i);
  }

  for(int i = 0; i < number; i++){
    printf("%d ",heap[i]);
  }
}
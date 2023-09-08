#include<stdio.h>
#include<algorithm>
using namespace std;

int number;

int main(){
  int data[1000000];
  scanf("%d", &number);
  for(int i=0; i < number; i++){
    scanf("%d",&data[i]);
  }
  sort(data, data + number);
  for(int i = 0; i < number; i++){
    printf("%d\n",data[i]);
  }
}

/*
위 문제는 데이터의 갯수가 100만 개인데 시간 제한이 1초이므로 
반드시 시간 복잡도 O(N * logN)으로 풀어야 한다.
=> 시간 복잡도가 O(n * logn)인 힙정렬,병합정렬,퀵정렬 로 풀어야 함
=> 퀵 정렬은 최악일 때 O(n^2)이므로 "기본 퀵정렬"으로는 풀지 못함

! STL 라이브러리에서 제공하는 sort() 함수는 퀵 정렬을 기반으로 하되 별도의
! 처리를 거쳐 최악의 경우에도 O(n * logn)을 보장한다.
*/

#include<stdio.h>

int main(){
  int i, j, min, index, temp;

  int array[10] = {1,10,5,8,7,6,4,3,2,9};
  for(i = 0;i < 10;i++){
    min = 9999;
    for(j = i;j<10;j++){
      if(min > array[j]){
        min = array[j];
        index = j;
      }
    }
    temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
  for(i = 0; i < 10; i++){
    printf("%d ",array[i]);
  }
}
/*
선택 정렬의 시간복잡도
=> 10번 + 9번 + 8번 + ... + 1
=> 등차수열 형태
=> 등차수열 공식 : 10 * (10 + 1) / 2  = 55


=> 선택 정렬의 수행 시간 : n(n+1) / 2
=> 선택 정렬의 시간 복잡도 : O(N^2)
=> Y = X^2 형태의 그래프로 X값이 증가할수록 처리하는 시간이 매우 가파르게 증가함
=> 매우 비효율적인 알고리즘!!
*/
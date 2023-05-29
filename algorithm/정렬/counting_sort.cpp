#include<stdio.h>

int main(){
  int temp;
  int count[5] = {0,}; // 범위가 5이하이기 때문에 5개까지 들어갈 공간을 만들어줌
  int array[30] = {
    1,3,2,4,3,2,5,3,1,2,
    3,4,4,3,5,1,2,3,5,2,
    3,1,4,3,5,1,2,1,1,1
  };

  for(int i = 0; i < 30; i++){
    count[array[i] - 1]++;
  }

  for(int i = 0; i < 5; i++){
    if(count[i] != 0){
      for(int j = 0; j < count[i]; j++){
        printf("%d", i + 1);
      }
    }
  }
}
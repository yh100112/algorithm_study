#include<stdio.h>

int main(){
  int arr[5][2];
  int cnt = 1;
  for(int i = 0; i <= 5; i++){
    for(int j = 0; j < 2; j++){
      arr[i][j] = cnt;
      cnt++; 
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 2; j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}
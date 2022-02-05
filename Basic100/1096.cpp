#include<stdio.h>

int main(){
  int board[20][20] = {0,};
  int num,x,y;
  scanf("%d",&num);

  for(int i = 0;i < num; i++){
    scanf("%d %d",&x,&y);
    board[x][y] = 1;
  }

  for(int i = 1; i < 20; i++){
    for(int j=1;j < 20; j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }


}
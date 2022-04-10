#include<stdio.h>

int main(){
  int board[20][20] = {0,};
  int a,n,x,y;
  for(int i=1; i <= 19; i++){
    for(int j = 1; j <= 19; j++){
      scanf("%d",&a);
      board[i][j] = a;
    }
  }

  scanf("%d",&n);

  for(int i = 0;i < n; i++){
    scanf("%d %d",&x,&y);
    for(int j = 1; j <= 19; j++){
      if(board[x][j] == 0) board[x][j] = 1;
      else board[x][j] = 0;
    }

    for(int j = 1; j <= 19; j++){
      if(board[j][y] == 0) board[j][y] = 1;
      else board[j][y] = 0;
    }

    
  }

  for(int i = 1; i <= 19; i++){
    for(int j = 1; j <= 19; j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
}
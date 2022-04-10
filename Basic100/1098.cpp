#include<stdio.h>

int main(){
  int h,w,n; 
  int l; 
  int d; 
  int x,y; 
  int i,j;

  scanf("%d %d",&h,&w);
  scanf("%d",&n);

  int board[h+1][w+1] = {0,};

  for(int i = 0; i < n; i++){
    scanf("%d %d %d %d",&l,&d,&x,&y);

    for(int i = 0; i < l; i++){
      if(d == 0){
        board[x][y] = 1;
        y++;
      }else if(d == 1){
        board[x][y] = 1;
        x++;
      }
    }

  }


  for(i = 1; i <= h; i++){
    for(j = 1; j <= w; j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
}


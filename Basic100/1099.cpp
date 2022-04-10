#include<stdio.h>

int main(){
  int maze[11][11];
  int i,j;
  int a;

  for(i = 1;i <= 10; i++){
    for(j = 1;j <= 10; j++){
      scanf("%d",&a);
      maze[i][j] = a;
    }
  }

  bool check = false;
  j = 2;
  for(i = 2; i <= 10; i++){
    if(maze[i][j] == 2){
      maze[i][j] = 9;
      break;
    }
    maze[i][j] = 9;

    if(i == 9 && j == 9){
      break;
    }
    if(maze[i][j+1] == 1){
      continue;
    }else if(maze[i][j+1] == 2){
      maze[i][j+1] = 9;
      break;
    }else{
      j++;
      for(j; j <= 10; j++){
        maze[i][j] = 9;
        if(maze[i][j+1] == 1){
          break;
        }else if(maze[i][j+1] == 2){
          maze[i][j+1] = 9;
          check = true;
          break;
        }       
      }
      if(check == true) break;
    }
  }

  for(i = 1;i <= 10; i++){
    for(j=1;j<=10;j++){
      printf("%d ",maze[i][j]);
    }
    printf("\n");
  }
}
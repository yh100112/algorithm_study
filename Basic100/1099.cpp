#include<stdio.h>

int main(){
  int maze[11][11];
  int i,j;
  int a;
  bool check = false;

  for(i = 1;i <= 10; i++){
    for(j = 1;j <= 10; j++){
      scanf("%d",&a);
      maze[i][j] = a;
    }
  }

  for(i = 2; i <= 10; i++){
    if(check == true){
      break;
    }

    for(j = 2; j <= 10; j++){
      if(maze[i][j] == 2){
        maze[i][j] = 9;
        check = true;
        break;
      }else if(maze[i][j] == 0){
        maze[i][j] = 9;
      }

      if(maze[i][j+1] == 1){
        break;
      }else if(maze[i][j+1] == 0){
        continue;
      }

    }
  }

  printf("\n");

  for(i = 1;i <= 10; i++){
    for(j=1;j<=10;j++){
      printf("%d ",maze[i][j]);
    }
    printf("\n");
  }
}
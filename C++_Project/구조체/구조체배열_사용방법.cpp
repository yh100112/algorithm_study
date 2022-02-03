#include<stdio.h>

struct Point2D{
  int x;
  int y;
};

int main(){
  Point2D p[5];

  for(int i=0;i < 5; i++){
    p[i].x = i;
    p[i].y = i;
  }

  for(int i = 0; i < 5; i++){
    printf("(%d, %d)\n",p[i].x,p[i].y);
  }

  return 0;
}
#include<stdio.h>

int main(){
  int i,j;
  for(i=0; i < 3; i++){
    printf("i i : %d | ",i);
    for(j=0; j<3;j++){
      i++;
      printf("i : %d\n",i);
    }
  }
}
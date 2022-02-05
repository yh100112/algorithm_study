#include<stdio.h>

int main(){
  int input;
  scanf("%d",&input);

  for(int i=1;i < input+1;i++){
    if(i%3 == 0){
      continue;
    }else{
      printf("%d ",i);
    }
  }
}
#include<stdio.h>

int main(){
  int input;
  int sum = 0;
  scanf("%d",&input);

  for(int i=1;i < input+1; i++){
    if(i%2 == 0){
      sum += i;
    }
  }
  printf("%d",sum);
}
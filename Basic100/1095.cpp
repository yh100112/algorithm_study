#include<stdio.h>

int main(){
  int count,a;
  int min;
  scanf("%d",&count);

  int attention_num[count] = {0,};
  for(int i = 0;i < count; i++){
    scanf("%d",&a);
    attention_num[i] = a;

    if(i == 0){
      min = a;
    }else{
      if(min >= a) min = a; 
    }
  }
  printf("%d",min);


}
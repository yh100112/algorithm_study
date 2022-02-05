#include<stdio.h>

int main(){
  int count,a;
  scanf("%d",&count);

  int attention[count]={0,};
  for(int i = 0;i < count; i++){
    scanf("%d",&a);
    attention[i] = a;
  }

  for(int i = count - 1; i >= 0; i--){
    printf("%d ",attention[i]);
  }
}
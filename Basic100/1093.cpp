#include<stdio.h>

int main(){
  int count,a;
  int check[24]={0,};
  scanf("%d",&count);

  for(int i = 0;i < count; i++){
    scanf("%d",&a);
    check[a]++;
  }

  for(int i = 1; i < 24; i++){
    printf("%d ",check[i]);
  }
}
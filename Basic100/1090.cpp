#include<stdio.h>
#include<math.h>

int main(){
  int a,r,n;
  scanf("%d %d %d",&a,&r,&n);

  int multi = 1;
  for(int i=0; i < n-1;i++){
    multi *= r;
  }

  printf("%.f",a*pow(r,n-1));
}
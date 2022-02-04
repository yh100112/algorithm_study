#include<stdio.h>
#include<math.h>

int main(){
  long long a,b,c;
  scanf("%lld %lld %lld",&a,&b,&c);

  printf("%.2f MB",(a*b*c)/pow(2,23));
}
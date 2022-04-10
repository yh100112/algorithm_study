#include<stdio.h>
#include<math.h>

int main(){
  long long h,b,c,s;
  scanf("%lld %lld %lld %lld",&h,&b,&c,&s);

  long long a = 1;
  for(int i=0;i<23;i++){
    a *= 2;
  }

  long long multiple =  h * b*c*s;
  double mb = multiple / double(a);
  printf("%.1lf MB",mb);
}
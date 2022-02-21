#include <stdio.h>
#include <iostream>

using namespace std;

int d[1001];

int tile(int n){
  if(n == 1) return 1;
  if(n == 2) return 2;
  if(d[n] != 0) return d[n];
  
  d[n] = (tile(n-1) + tile(n-2)) % 10007;
  return d[n];
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%d",tile(n));
}
#include<iostream>
using namespace std;

int func(int n, int r, int c) {
  // if (n == 2) {
  //   if (x == 0 && y == 0) return 0;
  //   else if(x == 0 && y == 1) return 1;
  //   else if(x == 1 && y == 1) return 2;
  //   return 3;
  // } -> 내가 한 것 이렇게 base condition을 놓으면 안됨.
  if(n == 0) return 0;
  int half = 1<<(n-1);
  if(r < half && c < half) return func(n-1, r, c);
  if(r < half && c >= half) return half * half + func(n-1, r, c-half);
  if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
  return 3*half*half + func(n-1, r-half, c-half);
}

int main() {
  int n,r,c;
  cin >> n >> r >> c;
  cout << func(n,r,c);
}
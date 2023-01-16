// a^b을 m으로 나눈 나머지 -> a^b mod m
#include<iostream>
using namespace std;
int func1(int a, int b, int m){
  int val = 1;
  while(b--) val *= a;
  return val % m;
}

// int overflow를 고려한 함수
using ll = long long;
ll func2(ll a, ll b, ll m){
  ll val = 1;
  while(b--) val = val * a % m; 
  // 곱하는 중간중간 m으로 나눈 나머지만 챙겨가면 됨
  // 2342356116 * 268921 * 29123의 일의 자리 구해보자
  // -> 각 수의 1의 자리인 6,1,3만 곱한 후 답이 8이라는 것을 알것이다.
  // 우린 이미 직관적으로 위 세 수의 곱의 1의자리 즉 10으로 나눈 나머지는 각각의 1의 자리를 곱한후 구하면 된다는 걸 안다.
  // 이 코드도 10이 m으로 달라진 것 뿐이지 다른게없다.
  // 결론 : a^b mod m 을 O(b)에 구할 수 있다.
  return val;
}

int main(){
  cout << func1(6,100,5) << endl;
  /*
  1이 아니라 0이 나오는 이유
  -> int overflow 때문. 6^100은 매우 큰 숫자이기 때문
  */
}
// a^b mod m을 구하는 문제에서 b가 최대 20억이라서 O(b)로 해결될 수 없는 문제
#include<iostream>
using namespace std;
using ll = long long;

// ll func(ll a, ll b, ll c) {
//   ll val = 1;
//   while(b--) val = val * a % c;
//   return val;
// }

// a^b mod c -> a^b을 c로 나눈 나머지를 구하는 함수
// 이 문제는 위 함수대로 하면 b가 20억이 넘어가서 O(b)로 구할 수 없는 경우이므로 다르게 생각해야 함.
// 1. 2^k승을 구할 수 있으면 2^2k승을 구할 수 있다. ( 2^k x 2^k 이므로 )
// 2. 2^(2k+1)승을 구할 수 있다. ( 2^2k에 2만 한번 더 곱해주면 되므로 )
// -> 위 두문장이 참이므로 2의 지수승을 귀납적으로 구할 수 있다. 
ll func(ll a, ll b, ll c) {
  if(b == 1) return a;
  ll val = func(a, b/2, c); // 반만 구한다.
  val = val * val % c; // 반 구한걸 제곱한다. ( 2^k x 2^k = 2^2k이므로)
  if (b % 2 == 0) return val;
  return val * a % c; 
}

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  cout << func(a,b,c);
}
// a^b mod m을 구하는 문제에서 b가 최대 20억이라서 O(b)로 해결될 수 없는 문제
#include<iostream>
using namespace std;

// a^b = a^(b/2) x a^(b/2)
long long a,b,c,k;

long long power(long long b){
  if(b == 0) return 1;
  if(b == 1) return a % c;

  k = power(b/2) % c;
  if(b % 2 == 0) 
    return k * k % c;
  else
    return k * k % c * a % c;
}

int main(){
  cin >> a >> b >> c;
  cout << power(b);
}
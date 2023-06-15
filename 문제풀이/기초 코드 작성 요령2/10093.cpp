#include<bits/stdc++.h>
using namespace std;

// 내가 짠 코드
/*
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a,b;
  cin >> a >> b;

  int gap = abs(b - a) - 1;

  if(a == b){
    gap = 0;
    cout << gap << "\n";
  }else{
    cout << gap << "\n";
    for(int i = 0; i < gap; i++){
      if(a < b) cout << ++a << " ";
      else cout << ++b << " ";
    }
  }
}
*/


//바킹독 코드
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a,b;
  cin >> a >> b;
  if(a > b) swap(a,b);
  
  if(a == b || b - a == 1) cout << 0;
  else{
    cout << b - a - 1 << "\n";
    for(long long i = a + 1; i < b; i++){
      cout << i << " ";
    }
  }
}
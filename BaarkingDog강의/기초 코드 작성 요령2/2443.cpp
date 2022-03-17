#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  //내가 한 것
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < i-1; j++) cout << " ";
    for(int j = 0; j < 2 * n - (2 * i - 1); j++) cout << "*";
    cout << "\n";
  }

  //바킹독 코드
  for(int i = n; i >= 1; i--){
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= 2 * i - 1; j++) cout << "*";
    // '*'의 오른쪽 공백은 출력하지 말아야 통과한다.
    cout << "\n";
  }
}
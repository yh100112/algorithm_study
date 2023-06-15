#include<bits/stdc++.h>
using namespace std;

//내가 짠 코드
/*
int a, result; 

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  result = 0;
  int min = 9999;
  for(int i = 0; i < 7; i++){
    cin >> a;
    if(a % 2 != 0){
      if(min > a) min = a;
      result += a;
    } 
  }
  if(result == 0) cout << -1;
  else {
    cout << result << "\n" << min;
  }

}
*/

//바킹독
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, odd = 0, sum = 0, min = 100;

  for(int i = 0; i < 7; i++){
    cin >> x;
    if(x & 1){ // 홀수는 이진수로 하면 2^0 자리가 항상 1이다. 짝수는 항상 0이다.
      odd += 1;
      sum += x;

      if(x < min){
        min = x;
      }
    }
  }

  if(odd) cout << sum << "\n" << min;
  else cout << "-1";
}
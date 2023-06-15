#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int max = 0;
  int idx;
  
  for(int i = 1; i <= 9; i++){
    cin >> n;
    if(n > max){
      max = n;
      idx = i;
    }
  }

  cout << max << "\n" << idx;
}

//max_element() 함수를 이용한 풀이
// int a[9];
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   for(int i = 0; i < 9; i++) cin >> a[i];
//   cout << *max_element(a, a+9) << "\n";
//   cout << max_element(a, a+9) - a + 1;
// }
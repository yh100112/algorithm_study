#include<bits/stdc++.h>
using namespace std;
string s;
int i, j;
int ret;


int main(){
  cin >> s;
  int cnt = 0;
  int k_idx = -1;
  int q_idx = -10;
  int a = 0;
  while(cnt < s.length()) {
    for(i = 0; i < s.length(); i++){
      if (s[i] == 'q') {
        s[i] = '-';
        q_idx = i;
        if (q_idx < k_idx) {
          ret++;
        }
        a++;
      }
      else if (s[i] == 'u' && a == 1) {
        s[i] = '-';
        a++;
      }
      else if (s[i] == 'a' && a == 2) {
        s[i] = '-';
        a++;
      }
      else if (s[i] == 'c' && a == 3) {
        s[i] = '-';
        a++;
      }
      else if (s[i] == 'k' && a == 4) {
        s[i] = '-';
        k_idx = i;
        a++;
      }
    }
    a = 0;
    q_idx = 0;
    cnt++;
  }

  for(i = 0; i < s.length(); i++){
    if(s[i] != '-') {
      cout << -1 << "\n";
      return 0;
    }
  }

  cout << ret << "\n";
}
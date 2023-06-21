#include<bits/stdc++.h>
using namespace std;
int ret;
string n;

int main(){
  cin >> n;
  int num = n.length();
  int cnt = 1; // 자릿수 1, 2, ...
  int b = 1; // 10, 100, ...
  string a = "9";
  while(true){
    if(num == cnt){
      ret += (stoi(n) - b + 1) * cnt;
      break;
    }
    else {
      ret += (stoi(a) - b + 1) * cnt; 
    }
    a += "9";
    cnt++;
    b *= 10;
  }
  cout << ret << "\n";
}
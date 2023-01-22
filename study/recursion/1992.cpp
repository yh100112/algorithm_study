#include<iostream>
#include<string>
using namespace std;
string map[64];

bool chk(int n, int x, int y){
  for(int i = x; i < x + n; ++i) {
    for(int j = y; j < y + n; ++j) {
      if (map[i][j] != map[x][y])
        return false;
    }
  }
  return true;
}

void solve(int n, int x, int y){
  if (chk(n,x,y)) {
    cout << map[x][y];
    return;
  }
  else {
    cout << "(";
    solve(n/2, x, y);
    solve(n/2, x, y + n/2);
    solve(n/2, x + n/2, y);
    solve(n/2, x + n/2, y + n/2);
  }
  cout << ")";
  return;
}

// 흰 0 검 1
int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; ++i)
    cin >> map[i];
  solve(n,0,0);
}
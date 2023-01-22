#include<iostream>
using namespace std;
int a[2200][2200];
int ans[3];

bool same(int x, int y, int n){
  for(int i = x; i < x + n; i++) {
    for (int j = y; j < y + n; j++) {
      if(a[x][y] != a[i][j])
        return false;
    }
  }
  return true;
}

void func(int x, int y, int n){
  if(same(x,y,n)) {
    ans[a[x][y] + 1]++;
    return;
  }
  else {
    int res = n/3;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        func(x + i * res, y + j * res, res);
      }
    }
  }
}


int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j){
      cin >> a[i][j];
    }
  }
  func(0,0,n);
  cout << ans[0] <<'\n' << ans[1] << '\n' << ans[2];
}
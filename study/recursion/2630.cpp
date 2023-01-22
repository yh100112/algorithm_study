#include<iostream>
using namespace std;
int a[150][150];
int ans[2];

bool same(int x, int y, int n){
  for(int i=x; i<x+n; i++){
    for(int j=y; j<y+n; j++){
      if(a[x][y] != a[i][j]){
        return false;
      }
    }
  }
  return true;
}

void solve(int x, int y, int n){
  if(same(x,y,n) == true){
    ans[a[x][y]]++;
    return;
  }
  else {
    for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
        solve(x + i * n/2, y + j * n/2, n/2);
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> a[i][j];
  solve(0,0,n);
  cout << ans[0] << "\n" << ans[1];
}
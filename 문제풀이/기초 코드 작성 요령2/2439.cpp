#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    for(int k = 0; k < n - i; k++){
      cout << " ";
    }
    for(int j = 0; j < i; j++){
      cout << "*";
    }
    cout << "\n";
  }
}
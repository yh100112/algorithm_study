#include<bits/stdc++.h>
using namespace std;

//³»°¡ Â§ ÄÚµå
/*
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= (2 * n - 1) / 2; i++){
    for(int j = 0; j < n-i; j++) cout << " ";
    for(int j = 0; j < 2 * i - 1; j++) cout << "*";
    cout << "\n";
  }

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < i-1; j++) cout << " ";
    for(int j = 0; j < 2 * n - (2 * i - 1); j++) cout << "*";
    cout << "\n";
  }
}
*/

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n - 1; i++){
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= 2 * i - 1; j++) cout << "*";
    cout <<"\n";
  }

  for(int j = 1; j <= 2 * n - 1; j++) cout << "*";
  cout <<"\n";

  for(int i = n - 1; i >= 1; i--){
    for(int j = 1; j <= n - i; j++) cout << " ";
    for(int j = 1; j <= 2 * i - 1; j++) cout << "*";
    cout << "\n";
  }
}
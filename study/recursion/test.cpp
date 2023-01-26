#include<iostream>
using namespace std;
char board[2200][2200];

void func(int x, int y, int n){
  if(n == 3){
    for(int i = x; i < x + 3; ++i){
      for(int j = y; j < y + 3; ++j) {
        if (i == x + 1 && j == y + 1)
          continue;
        board[i][j] = '*';
      }
    }
    return;
  }
  else {
    int next_n = n / 3;
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        if (i == 1 && j == 1)
          continue;
        func(x + i * next_n, y + j * next_n, next_n);
      }
    }
  }
}

int main(){
  int n;
  cin >> n;

  for(int i = 0; i < n; ++i)
    fill(board[i], board[i] + n, ' ');
  
  func(0,0,n);
  for(int i = 0; i < n; ++i)
    cout << board[i] << '\n';
}

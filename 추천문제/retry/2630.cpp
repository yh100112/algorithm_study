#include<bits/stdc++.h>
using namespace std;
int n, a[130][130], ret[2];

bool check(int y, int x, int n) {
  int color = a[y][x];
  for (int i = y; i < y + n; i++) {
    for (int j = x; j < x + n; j++) {
      if (color != a[i][j]) return false;
    }
  }
  return true;
}

void go(int y, int x, int n) {
  if (check(y, x, n)) {
    ret[a[y][x]]++;
    return;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      go(y + i * (n / 2), x + j * (n / 2), n / 2);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  
  go(0, 0, n);
  cout << ret[0] << "\n" << ret[1] << "\n";
}
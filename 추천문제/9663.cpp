#include<bits/stdc++.h>
using namespace std;
bool isused[300];
bool isused2[300];
bool isused3[300];
int n, ret;

void go(int y) {
  if (y == n) {
    ret++;
    return;
  }
  for (int x = 0; x < n; x++) {
    if (isused[x] || isused2[x + y] || isused3[x - y + n - 1]) continue;
    isused[x] = 1;
    isused2[x + y] = 1;
    isused3[x - y + n - 1] = 1;
    go(y + 1);
    isused[x] = 0;
    isused2[x + y] = 0;
    isused3[x - y + n - 1] = 0;
  }
}

int main() {
  cin >> n;
  go(0);
  cout << ret << "\n";
}
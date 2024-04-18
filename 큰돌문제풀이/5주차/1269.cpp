#include<bits/stdc++.h>
using namespace std;
int n, m, num, ret;
map<int,int> m1;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> num;
    m1[num]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> num;
    m1[num]++;
  }

  for (auto& i : m1) {
    if (i.second == 1) ret++;
  }
  cout << ret << "\n";
}

/*
문제에서 counting이 나온다?
counting star~ map or 배열~
*/
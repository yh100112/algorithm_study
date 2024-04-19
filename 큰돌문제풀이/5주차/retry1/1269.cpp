#include<bits/stdc++.h>
using namespace std;
int n, m, num, cnt;
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

  for (auto& i : m1)
    if (i.second == 1)
      cnt++;
  cout << cnt << "\n";
}
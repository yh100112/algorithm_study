#include<bits/stdc++.h>
using namespace std;
int n, m, visited[10];

void print(vector<int>& v) {
  for (auto& i : v)
    cout << i << ' ';
  cout << "\n";
}

void go(int idx, vector<int>& v) {
  if (idx == m) {
    print(v);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    visited[i] = 1;
    v.push_back(i);
    go(idx + 1, v);
    visited[i] = 0;
    v.pop_back();
  }
}

int main() {
  cin >> n >> m;
  vector<int> v;
  go(1, v);
}

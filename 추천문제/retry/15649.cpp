#include<bits/stdc++.h>
using namespace std;
int n, m;
int visited[10];

void go(vector<int>& v) {
  if (v.size() == m) {
    for (auto i : v)
      cout << i << " ";
    cout << "\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    v.push_back(i);
    visited[i] = 1;
    go(v);
    v.pop_back();
    visited[i] = 0;
  }
}


int main() {
  cin >> n >> m;
  vector<int> v;
  go(v);
}
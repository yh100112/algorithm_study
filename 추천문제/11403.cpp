#include<bits/stdc++.h>
using namespace std;
int n, num, ret[104][104], visited[104], start;
vector<int> v[104];

void go(int here) {
  for (auto& next : v[here]) {
    if (visited[next]) continue;
    visited[next] = 1;
    ret[start][next] = 1;
    go(next);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> num;
      if (num)
        v[i].push_back(j);
    }
  }

  for (int i = 0; i < n; i++) {
    memset(visited, 0, sizeof(visited));
    start = i;
    go(i);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ret[i][j] << " "; 
    cout << "\n";
  }
}
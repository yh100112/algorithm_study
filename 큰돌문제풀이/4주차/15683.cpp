#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1 ,0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[10][10], ret = INT_MAX;
vector<pair<int,int>> v;

vector<pair<int,int>> spread(int idx, int dir) {
  vector<pair<int,int>> v_;
  int y = v[idx].first;
  int x = v[idx].second;
  if (a[y][x] == 1) {
    while(true) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
      a[ny][nx] = 8;
      y = ny;
      x = nx;
      v_.push_back({y,x});
    }
  }
  else if (a[y][x] == 2) {
    for (int i = 0; i <= 2; i += 2) {
      while(true) {
        int ny = y + dy[(dir + i) % 4];
        int nx = x + dx[(dir + i) % 4];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
        a[ny][nx] = 8;
        y = ny;
        x = nx;
        v_.push_back({y,x});
      }
    }
  }
  else if (a[y][x] == 3) {
    for (int i = 0; i < 2; i++) {
      while(true) {
        int ny = y + dy[(dir + i) % 4];
        int nx = x + dx[(dir + i) % 4];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
        a[ny][nx] = 8;
        y = ny;
        x = nx;
        v_.push_back({y,x});
      }
    }
  }
  else if (a[y][x] == 4) {
    for (int i = 0; i < 3; i++) {
      while(true) {
        int ny = y + dy[(dir + i) % 4];
        int nx = x + dx[(dir + i) % 4];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
        a[ny][nx] = 8;
        y = ny;
        x = nx;
        v_.push_back({y,x});
      }
    }
  }
  else if (a[y][x] == 5) {
    for (int i = 0; i < 4; i++) {
      while(true) {
        int ny = y + dy[(dir + i) % 4];
        int nx = x + dx[(dir + i) % 4];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
        a[ny][nx] = 8;
        y = ny;
        x = nx;
        v_.push_back({y,x});
      }
    }
  }
  return v_;
}

void go(int idx) {
  if (idx == v.size()) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int  j = 0; j < m; j++)
        if (a[i][j] == 0) cnt++;
    ret = min(ret, cnt);
    return;
  }

  // rotate
  for (int dir = 0; dir < 4; dir++) {
    vector<pair<int,int>> temp = spread(idx, dir);
    go(idx + 1);
    for(auto i : temp) a[i.first][i.second] = 0;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] != 6 && a[i][j] != 0) v.push_back({i,j});
    }
  }
  go(0);
  cout << ret << "\n";
}
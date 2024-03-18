#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, board[54][54], temp[54][54], e,f,g, INF = 987654321;
int ret = INF;
struct A {
  int r, c, s; // row, col, 칸 수
};
vector<A> v;
vector<int> v_idx;

int min_sum() {
  int mn = INF;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j)
      sum += temp[i][j];
    mn = min(mn, sum);
  }
  return mn;
}

void go(int idx) {
  int r = v[idx].r;
  int c = v[idx].c;
  int s = 1;
  int y, x;
  int temp_2[54][54];
  memcpy(temp_2, temp, sizeof(temp));

  while (true) {
    if (s > v[idx].s) break;
    y = r - s;
    x = c - s;
    vector<pair<int,int>> r_idx; // 회전해야 할 위치
    vector<pair<int,int>> temp_r_idx;
    r_idx.push_back({y,x});

    int dir = 0;
    while (dir < 4) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (ny < r - s || ny > r + s || nx < c - s || nx > c + s) { // 방향 변경
        dir++;
      }
      else {
        r_idx.push_back({ny,nx});
        y = ny;
        x = nx;
      }
    }

    // 배열 회전
    temp_r_idx = r_idx;
    rotate(r_idx.rbegin(), r_idx.rbegin() + 1, r_idx.rend());
    for (int i = 0; i < r_idx.size(); ++i)
      temp[temp_r_idx[i].first][temp_r_idx[i].second] = temp_2[r_idx[i].first][r_idx[i].second];

    ++s;
  }
}

int main(){
  cin >> n >> m >> k; // k : 회전 연산 개수
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j];

  for (int i = 0; i < k; ++i) {
    cin >> e >> f >> g;
    --e, --f;
    v.push_back({e, f, g});
    v_idx.push_back(i);
  }

  do {
    memcpy(temp, board, sizeof(board));
    for (auto idx : v_idx)
      go(idx); // 회전
    ret = min(ret, min_sum()); // 배열의 값
  } while (next_permutation(v_idx.begin(), v_idx.end()));

  cout << ret << "\n";
}
#include<bits/stdc++.h>
using namespace std;
int n, m, T, x, d, k, a[54][54], ret, visited[54][54], y;
const int dy[] = {-1, 0, 1, 0}; // 인접한 원으로 이동할 때 dx[]는 안 이동함
const int dx[] = {0, 1, 0, -1}; // 같은 원 안에 있는 인접한 위치로 이동할 때에는 dy[]는 안 이동함
bool flag = 1;

void _rotate(int y, int dir, int k) {
  vector<int> v;
  for (int i = 0; i < m; i++)
    v.push_back(a[y][i]); // 현재 원에 있는 숫자들
  
  if (dir == 1) rotate(v.begin(), v.begin() + k, v.end()); // 반시계
  else rotate(v.begin(), v.begin() + m - k, v.end()); // 시계

  for (int i = 0; i < m; i++)
    a[y][i] = v[i];
}

// 인접한 곳 전체 탐색
void dfs(int y, int x) {
  // 인접한 원(앞, 뒤 -1 ,1) / 같은 원 내의 인접한 숫자 (우 좌 1, -1) -> 이야 이거 아이디어 기가막힌다;;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i]; // 인접한 원으로 이동
    int nx = (x + dx[i] + m) % m; // 같은 원 안에서 옆에 인접한 수 -> ? m 왜 더해주지
    if (ny < 0 || ny >= n || visited[ny][nx]) continue;
    if (a[y][x] == a[ny][nx]) {
      visited[y][x] = visited[ny][nx] = 1;
      flag = 0; // 인접한 게 있다면 0으로 체크
      dfs(ny, nx);
    }
  }
}

bool findAdj() {
  flag = 1;
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 || visited[i][j]) continue;
      dfs(i, j);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (visited[i][j]) a[i][j] = 0;
  return flag;
}

void setAverage() {
  int sum = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) continue;
      sum += a[i][j];
      cnt++;
    }
  }
  double av = (double)sum / cnt;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 0) continue;
      if((double)a[i][j] > av)      a[i][j]--;
      else if((double)a[i][j] < av) a[i][j]++;
    }
  }
}

int main() {
  cin >> n >> m >> T;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  for (int i = 0; i < T; i++) {
    cin >> x >> d >> k;
    for (int j = x - 1; j < n; j += x) {  // y의 배수인 원판을 돌린다.
      _rotate(j, d, k);
    }
    if (findAdj()) setAverage();
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ret += a[i][j];
  cout << ret << "\n";
}
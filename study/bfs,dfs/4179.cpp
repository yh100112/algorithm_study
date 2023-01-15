#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m;

int main(void) {
  cin >> n >> m; // 가로 세로
  int i,j;
  for(i = 0; i < n; ++i) {
    fill(dist1[i], dist1[i] + m, -1);
    fill(dist2[i], dist2[i] + m, -1);
  }

  for(i = 0; i < n; ++i)
    cin >> board[i]; // 여기서 이렇게 안하고 바로 뒤 포문에서 넣어가면서 하면 런타임 에러 세그폴트 발생
  queue<pair<int,int>> Q1; // F
  queue<pair<int,int>> Q2; // J
  for(i = 0; i < n; ++i) {
    for(j = 0; j < m; ++j) {
      if(board[i][j] == 'F') {
        dist1[i][j] = 0;
        Q1.push({i,j});
      }
      if(board[i][j] == 'J') {
        dist2[i][j] = 0;
        Q2.push({i,j});
      }
    }
  }

  // 불 BFS
  while(!Q1.empty()){
    auto cur = Q1.front(); Q1.pop();
    for(int dir = 0; dir < 4; ++dir) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
      dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
      Q1.push({nx,ny});
    }
  }

  // 지훈 BFS
  while(!Q2.empty()){
    auto cur = Q2.front(); Q2.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        cout << dist2[cur.X][cur.Y] + 1;
        return 0;
      }
      if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      // 불의 위치를 추가로 따져줌
      if(dist1[nx][ny] >= 0 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;
      dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
      Q2.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE";
}
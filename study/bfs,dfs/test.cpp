#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int board[500][500];
bool vis[500][500];
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];
  int mx = 0; // 그림 최대값
  int num = 0; // 그림의 수
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(board[i][j] == 0 || vis[i][j]) continue;
      num++;
      queue<pair<int,int>> Q;
      vis[i][j] = 1;
      Q.push({i,j});
      int area = 0;
      while(!Q.empty()){
        area++;
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
      mx = max(area,mx);
    }
  }
  cout << num << '\n' << mx;
}
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int n,m;
string board[102];
int dist[102][102];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> board[i];
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      dist[i][j] = -1;
    }
  }

  queue<pair<int,int>> Q;
  Q.push({0,0});
  dist[0][0] = 1;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '0' || dist[nx][ny] > 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
    }
  }

  cout << dist[n-1][m-1];
}
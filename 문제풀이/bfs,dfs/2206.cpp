#include<iostream>
#include<utility>
#include<queue>
#include<tuple>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char board[1000][1000];
int dist[1000][1000][2];
// dist[curX][curY][0] : 벽을 하나도 부수지 않고 (curX,curY)까지 오는데 걸리는 비용
// dist[curX][curY][1] : 벽을 하나만 부수고 (curX,curY)까지 오는데 걸리는 비용, (curX,curY)가 벽이라서 부수는 경우 포함

int n,m;
int  bfs(){
  for(int i = 0 ; i < n; ++i)
    for(int j = 0; j < m; ++j)
      dist[i][j][0] = dist[i][j][1] = -1;
  dist[0][0][0] = dist[0][0][1] = 1;
  queue<tuple<int, int, int>> q;
  q.push({0,0,0}); // 벽을 하나도 부수지 않은 상태에서 (0,0) 시작
  
  while(!q.empty()){
    int curX,curY,broken;
    tie(curX,curY,broken) = q.front();
    if(curX == n-1 && curY == m-1)
      return dist[curX][curY][broken];
    
    q.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny][broken] != -1) continue;
      // 길
      if(board[nx][ny] == '0') {
        dist[nx][ny][broken] = dist[curX][curY][broken] + 1;
        q.push({nx,ny,broken});
      }
      // 벽 ( 벽을 부순 적이 없는 경우 )
      else if(board[nx][ny] == '1' && broken == 0) {
        dist[nx][ny][broken + 1] = dist[curX][curY][broken] + 1;
        q.push({nx, ny, broken + 1});
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> board[i][j];
  
  cout << bfs();

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << dist[i][j][0] << " ";
    }
    cout << endl;
  }
  cout << "-----------" << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << dist[i][j][1] << " ";
    }
    cout << endl;
  }
}


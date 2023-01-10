#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int dist[1002][1002]; // 전역으로 선언한 int나 int배열은 초기화를 안하면 0으로 채워짐
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// 익은 토마토 : 1 익지 않은 토마토 : 0 토마토가 없는 칸 : -1
// 모든 시작점을 큐에 넣고 앞에서 한 것과 같이 bfs를 돌리면 됨
int main(void){
  cin >> m >> n;
  queue<pair<int,int> > Q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1) // 익은 토마토는 큐에 삽입
        Q.push({i,j});
      if(board[i][j] == 0) // 익지 않은 토마토는 dist값을 -1로 세팅
        dist[i][j] = -1; // 익은 토마토가 들어있거나 빈칸인 곳은 dist값이 0인 것을 인지
    }
  }
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y]+1;
      Q.push({nx,ny});
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(dist[i][j] == -1){
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;
}
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int n,m; // 세로, 가로
int board[100][100];
bool vis[100][100];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }
  int time = 0;
  vector<int> delete_cheese_num;

  // 매번 새롭게 0,0부터 bfs  
  while(true) {
    int cnt = 0;
    queue<pair<int,int>> Q;
    vis[0][0] = true;
    Q.push({0,0});
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(vis[nx][ny]) continue;
        if(board[nx][ny] == 1) { // 가장자리 치즈
          board[nx][ny] = 0;     
          vis[nx][ny] = 1;
          cnt++;
        }
        else{
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
    }
    
    delete_cheese_num.push_back(cnt);

    // 방문처리 초기화
    for(int i = 0; i < n; i++)
      fill(vis[i], vis[i] + m, 0);

    // 마지막 치즈
    if(cnt == 0)
      break;
    time++;
  }
  cout << time << "\n";
  cout << delete_cheese_num[delete_cheese_num.size() - 2] << "\n";

}
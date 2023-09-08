#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int board[51][51];
int vis[51][51];
int m,n; // 가로,세로

int main(){
  int t,k;
  int i,j;
  cin >> t;

  int test_case_cnt = t;
  while(t--){
    cin >> m >> n >> k;
    while(k--){
      int x,y;
      cin >> x >> y;
      board[y][x] = 1;
    }
    int num = 0;
    for(int a = 0; a < n; a++){
      for(int b = 0; b < m; b++){
        if(board[a][b] == 0 || vis[a][b]) continue;
        num++;
        queue<pair<int,int>> Q;
        Q.push({a,b});
        vis[a][b] = 1;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
          }
        }
      }
    }
    cout << num << "\n";

    for(int i = 0; i < n; i++){
      fill(board[i], board[i] + m, 0);
      fill(vis[i], vis[i] + m, 0);
    }
  }
}
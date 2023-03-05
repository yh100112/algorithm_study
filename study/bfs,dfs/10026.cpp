#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define X first
#define Y second
string board[101];
int vis[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> board[i];
  
  int num = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vis[i][j]) continue;
      num++;
      queue<pair<int,int>> Q;
      vis[i][j] = true;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny]) continue;
          vis[nx][ny] = true;
          Q.push({nx,ny});
        }
      }
    }
  }
  cout << num << " ";
  num = 0;
  for(int i = 0; i < n; i++)
    fill(vis[i], vis[i]+n, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 'G')
        board[i][j] = 'R';
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vis[i][j]) continue;
      num++;
      queue<pair<int,int>> Q;
      vis[i][j] = true;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny]) continue;
          vis[nx][ny] = true;
          Q.push({nx,ny});
        }
      }
    }
  }
  cout << num;
}
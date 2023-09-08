#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;
int board[100][100];
int board2[100][100];
int vis[100][100];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];

  int mx = 0;
  // 높이
  for(int h = 0; h <= 100; h++){
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(board[i][j] <= h) // 물에 잠기는 지역
          board2[i][j] = 1;
      }
    }
    for(int i = 0; i < n; i++)
      fill(vis[i], vis[i] + n, 0);

    int num = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(board2[i][j] == 1 || vis[i][j] == 1) continue;
        num++;
        queue<pair<int,int>> Q;
        Q.push({i,j});
        vis[i][j] = 1;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board2[nx][ny] == 1 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny}); 
          }
        }
        mx = max(mx,num);
      }
    }
  }
  cout << mx;
}

/*
문제는 쉬웠지만 주의할 점
문제에 써져있는 "아무 지역도 물에 잠기지 않을 수도 있다" -> 이건 비가 안올수도 있다는 뜻 ( 즉, h = 0도 가능하다는 것!)
*/
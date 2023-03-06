#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define X first
#define Y second
int board[100][100];
int dist[100][100];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m,k;
int x,y,xx,yy;

int main(){
  cin >> m >> n >> k;
  
  while(k--) {
    cin >> x >> y >> xx >> yy;    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if((x <= i && i < xx) && (y <= j && j < yy)) // 직사각형 범위
          board[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < n; i++)
    fill(dist[i], dist[i]+m, -1);

  vector<int> area;
  int num = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 1 || dist[i][j] != -1) continue;
      num++;
      queue<pair<int,int>> Q;
      Q.push({i,j});
      dist[i][j] = 0;
      int cnt = 0;
      while(!Q.empty()){
        cnt++;
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
          dist[nx][ny] = dist[cur.X][cur.Y] + 1;
          Q.push({nx,ny});
        }
      }
      area.push_back(cnt);
    }
  }
  sort(area.begin(),area.end());
  cout << num << "\n";
  for(auto& v: area)
    cout << v << " ";
}

/*
풀 때 어려웠던 점
전형적인 bfs라 코드 자체는 복잡하지 않다.
하지만 좌표평면에 (x,y)로 값을 주는 형태로 이걸 2차원 배열에 알맞게 범위를 넣어줘야 한다.
이 때 2차원 배열은 위부터 아래로 인덱스가 내려가는 형태라서 
기존에 알고 있던 x좌표, y좌표의 좌표평면을 2차원 배열에 맞게 시계방향으로 90도 회전시켜서 좌표를 생각해야 문제가 풀린다.
-> 그러면 n은 세로가 되고 m은 가로가 된다.
*/


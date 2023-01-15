#include<utility>
#include<iostream>
#include<queue>
using namespace std;
#define X first
#define Y second
int board[502][502] = 
{ {1,1,1,0,1,0,0,0,0,0},
  {1,0,0,0,1,0,0,0,0,0},
  {1,1,1,0,1,0,0,0,0,0},
  {1,1,0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vist[502][502];
int n = 7, m = 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
  queue<pair<int,int>> Q;
  vis[0][0] = 1;
  Q.push({0,0});

  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 0 || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      Q.push({nx},ny);
    }
  }
}
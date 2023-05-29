#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
queue<pair<int,int>> Q1; // 불
queue<pair<int,int>> Q2; // 상근
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int t,w,h; // 너비 높이

int main(){
  cin >> t;
  while(t--){
    cin >> w >> h;
    for(int i = 0; i < h; i++) {
      fill(dist1[i], dist1[i] + w, -1);
      fill(dist2[i], dist2[i] + w, -1);
      cin >> board[i];
    }

    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(board[i][j] == '*') { // 불
          dist1[i][j] = 0;
          Q1.push({i,j});
        }
        if(board[i][j] == '@'){ // 상근
          dist2[i][j] = 0;
          Q2.push({i,j});
        }
      }
    }


    // 불 bfs
    while(!Q1.empty()){
      auto cur = Q1.front(); Q1.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
        dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
        Q1.push({nx,ny});
      }
    }

    // 상근 bfs
    bool success = false;
    while(!Q2.empty()){
      auto cur = Q2.front(); Q2.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
          success = true; 
          cout << dist2[cur.X][cur.Y] + 1 << "\n";
          Q2 = queue<pair<int,int>>(); // 이 부분 안넣어줘서 문제 발생
          break;
        }
        if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
        if(dist1[nx][ny] != -1 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;
        dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
        Q2.push({nx,ny});
      }
    }
    if(success == false)
      cout << "IMPOSSIBLE\n";
  }
}

/*
반레
#.###
#.#*#
#.#.#
#@#.#

-> 이거일 경우 @는 1 4 두개가 출력되기 때문에 탈출한 순간 큐를 초기화시켜줘야 함
*/
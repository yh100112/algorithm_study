#include<iostream>
#include<queue>
#include<utility>
#include<tuple>
using namespace std;
int dist[30][30][30];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};
int l,r,c;
int curX, curY, curZ;
queue<tuple<int,int,int>> Q;

int main(){
  while(true){
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0)
      break;
    
    char board[30][30][30];
    for(int i = 0; i < l; i++)
      for(int j = 0; j < r; j++)
        fill(dist[i][j], dist[i][j] + c, 0);

    for(int i = 0; i < l; i++){
      for(int j = 0; j < r; j++){
        for(int k = 0; k < c; k++){
          cin >> board[i][j][k];
          if(board[i][j][k] == 'S')
            Q.push({i,j,k});
          if(board[i][j][k] == '.') // 갈 수 있는 곳
            dist[i][j][k] = -1;
        }
      }
    }
    
    bool escape = false;
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      tie(curZ,curX,curY) = cur;
      for(int dir = 0; dir < 6; dir++){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        int nz = curZ + dz[dir];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
        if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] > 0) continue;

        dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
        if(board[nz][nx][ny] == 'E'){
          cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
          Q = queue<tuple<int,int,int>>();
          escape = true;
          break; 
        }
        Q.push({nz,nx,ny});
      }
    }

    if(escape == false)
      cout << "Trapped!" << "\n";
  }
}

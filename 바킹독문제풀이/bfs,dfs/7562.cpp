#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int dist[302][302];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int t, l;

int main(){
  cin >> t;
  while(t--) {
    cin >> l;
    for(int i = 0; i < l; i++)
      fill(dist[i], dist[i] + l, -1);

    queue<pair<int,int>> Q;
    int x, y, xx, yy;
    cin >> x >> y;
    Q.push({x,y});
    dist[x][y] = 0;

    cin >> xx >> yy; // x,y 도착지

    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      for(int dir = 0; dir < 8; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
        if(dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx,ny});
      }
    }
    cout << dist[xx][yy] << "\n";
  }
}
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
#define X first
#define Y second
string board[26];
int vis[26][26];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> board[i];
  
  int num = 0;
  vector<int> area;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == '0' || vis[i][j] != 0) continue;
      num++;
      queue<pair<int,int>> Q;
      Q.push({i,j});
      vis[i][j] = 1;

      int cnt = 0;
      while(!Q.empty()){
        cnt++;
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(board[nx][ny] == '0' || vis[nx][ny] != 0) continue;
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
      area.push_back(cnt);
    }
  }

  sort(area.begin(),area.end());
  cout << num << "\n";
  for(auto& v: area)
    cout << v << "\n";
}
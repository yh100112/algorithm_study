#include<bits/stdc++.h>
using namespace std;
int n;
string ori[52];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> ori[i][j];
    }
  }
  
  int mx = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int curX = i;
      int curY = j;
      for(int ret = 0; ret < 4; ret++){
        int nx = curX + dx[ret];
        int ny = curY + dy[ret];
        if(nx < 0 || nx >= n || ny < 0 || ny >= 0) continue;
        swap(ori[curX][curY], ori[nx][ny]);
        // 가로 세로로 카운팅해서 연속하는것 체크
      }
    }
  }
}
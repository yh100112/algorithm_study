#include<bits/stdc++.h>
using namespace std;
int R, C, K, visited[7][7], cnt;
char a[7][7];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void go(int y, int x){
    if(y == 0 && x == C-1){
        if(visited[y][x] == K) cnt++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1;
        go(ny,nx);
        visited[ny][nx] = 0;
    }
}
int main(){
    cin >> R >> C >> K; // r : 가로 , c : 세로
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> a[i][j]; 
    
    visited[R-1][0] = 1;
    go(R-1, 0);
    cout << cnt << "\n";
}
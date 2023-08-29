#include<bits/stdc++.h>
using namespace std;
int R, C, ret, ny, nx, visited[30];
char a[21][21];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
void go(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = a[ny][nx] - 'A';
        if(visited[next] == 0){
            visited[next] = 1;
            go(ny, nx, cnt + 1);
            visited[next] = 0;
        }
    }
    return;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    visited[a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << '\n';
}
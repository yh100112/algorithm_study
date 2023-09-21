#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r, c, visited[30], ret = -987654321;
char a[24][24];

void go(int y, int x, int cnt){
    bool flag = false;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[a[ny][nx] - 'A']) continue;
        flag = true;
        visited[a[ny][nx] - 'A'] = 1;
        go(ny,nx, cnt + 1);
        visited[a[ny][nx] - 'A'] = 0;
    }
    if(!flag) ret = max(ret, cnt);
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    
    visited[a[0][0] - 'A'] = 1;
    go(0,0,1);
    cout << ret << '\n';
}
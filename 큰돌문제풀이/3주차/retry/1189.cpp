#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r,c,k, visited[7][7], ret;
char a[7][7];

void go(int y, int x, int cnt){
    if(y == 0 && x == c - 1){
        if(cnt == k)
            ret++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
        if(a[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(ny,nx,cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    visited[r-1][0] = 1; // 출발점
    go(r-1,0,1);
    cout << ret << "\n";
}

// 첫 줄에 거리가 K인 가짓수를 출력한다.
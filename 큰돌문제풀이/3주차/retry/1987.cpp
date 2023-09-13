#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int R, C, ret = -987654321, check[30];
char a[24][24];

void go(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = a[ny][nx] - 'A';
        if(check[next]) continue;
        check[next] = 1;
        go(ny,nx, cnt + 1);
        check[next] = 0;
    }
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    check[a[0][0] - 'A'] = 1;
    go(0,0,1);
    cout << ret << "\n";
}
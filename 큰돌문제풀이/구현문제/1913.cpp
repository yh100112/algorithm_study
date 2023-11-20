#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, a[1004][1004], dir = 1, cnt = 1, num, retY, retX;
int sy, sx, ey, ex;

void go(int y, int x, int num){
    if(y == sy - 1 && x == sx){
        dir++;
        cnt++;
        sy = n / 2 - cnt;
        sx = n / 2 - cnt;
        ey = n / 2 + cnt;
        ex = n / 2 + cnt;
    }
    else{
        if(y == sy && x == ex) dir++;
        if(y == ey && x == ex) dir++;
        if(y == ey && x == sx) dir++;
    }
    dir = dir % 4;

    a[y][x] = num + 1; 
    if(num + 1 == n*n) return;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    go(ny, nx, num + 1);
}

int main(){
    cin >> n >> num;
    a[n / 2][n / 2] = 1;
    sy = n / 2 - cnt;
    sx = n / 2 - cnt;
    ey = n / 2 + cnt;
    ex = n / 2 + cnt;
    go(n / 2 - 1, n / 2, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
            if(a[i][j] == num) retY = i, retX = j;
        }
        cout << '\n';
    }
    cout << retY + 1 << ' ' << retX + 1 << '\n';
}
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n,m,y,x,d,ret,a[54][54];

bool check(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx]) continue;
        if (a[ny][nx] == 0) // 청소되지 않은 빈칸이 있는 경우
            return true;
    }
    return false;
}

void go(int y, int x, int d) {
    if(a[y][x] == 0) {
        a[y][x] = 2; // 청소
        ret++;
    }

    if (check(y,x)) {
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4; // 반시계 방향으로 회전
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny < 0|| ny >= n || nx < 0 || nx >= m) continue;
            if (a[ny][nx]) continue; // 벽 or 이미 청소된 칸
            go(ny,nx,d);
            break;
        }
    }
    else {
        int p_y = y + dy[(d + 2) % 4];
        int p_x = x + dx[(d + 2) % 4];
        if (a[p_y][p_x] == 1)
            return;
        go(p_y, p_x, d);
    }
}

int main() {
    cin >> n >> m;
    cin >> y >> x >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    go(y, x, d);
    cout << ret << "\n";
}
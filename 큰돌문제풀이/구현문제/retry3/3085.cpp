#include<bits/stdc++.h>
using namespace std;
int n, visited[52][52], ret = -987654321;
char a[52][52];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void go() {
    int max_y = -1;
    int max_x = -1;
    for (int y = 0; y < n; ++y) { // 세로
        char c = a[y][0];
        int cnt = 0;
        for (int x = 0; x < n; ++x) {
            if (c == a[y][x])
                ++cnt;
            else {
                max_y = max(max_y, cnt);
                cnt = 1;
                c = a[y][x];
            }
        }
        if (cnt)
            max_y = max(max_y, cnt);
    }
    for (int x = 0; x < n; ++x) {
        char c = a[0][x];
        int cnt = 0;
        for (int y = 0; y < n; ++y) {
            if (c == a[y][x])
                ++cnt;
            else {
                max_x = max(max_x, cnt);
                cnt = 1;
                c = a[y][x];
            }
        }
        if (cnt)
            max_x = max(max_x, cnt);
    }
    ret = max(ret, max(max_x, max_y));
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = 1;
            for (int dir = 0; dir < 4; ++dir) {
                int ny = i + dy[dir];
                int nx = j + dx[dir]; 
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
                if (a[ny][nx] == a[i][j]) continue;
                swap(a[ny][nx], a[i][j]);
                go();
                swap(a[ny][nx], a[i][j]);
            }
        }
    }
    cout << ret << "\n";
}
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int a[10][10], n, m, ret = INT_MAX;
vector<pair<int,int>> cctv;

vector<pair<int,int>> spread(int idx, int dir) {
    vector<pair<int,int>> v_;
    int y = cctv[idx].first;
    int x = cctv[idx].second;
    if (a[y][x] == 1) {
        while(true) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
            if (a[ny][nx] == 0) {
                a[ny][nx] = 8;
                v_.push_back({ny,nx});
            }
            y = ny;
            x = nx;
        }
    }
    else if (a[y][x] == 2) {
        for (int i = 0; i < 4; i += 2) {
            int y_ = y;
            int x_ = x;
            while(true) {
                int ny = y_ + dy[(dir + i) % 4];
                int nx = x_ + dx[(dir + i) % 4];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
                if (a[ny][nx] == 0) {
                    a[ny][nx] = 8;
                    v_.push_back({ny,nx});
                }
                y_ = ny;
                x_ = nx;
            }
        }
    }
    else if (a[y][x] == 3) {
        for (int i = 0; i < 2; i++) {
            int y_ = y;
            int x_ = x;
            while(true) {
                int ny = y_ + dy[(dir + i) % 4];
                int nx = x_ + dx[(dir + i) % 4];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
                if (a[ny][nx] == 0) {
                    a[ny][nx] = 8;
                    v_.push_back({ny,nx});
                }
                y_ = ny;
                x_ = nx;
            }
        }
    }
    else if (a[y][x] == 4) {
        for (int i = 0; i < 3; i++) {
            int y_ = y;
            int x_ = x;
            while(true) {
                int ny = y_ + dy[(dir + i) % 4];
                int nx = x_ + dx[(dir + i) % 4];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
                if (a[ny][nx] == 0) {
                    a[ny][nx] = 8;
                    v_.push_back({ny,nx});
                }
                y_ = ny;
                x_ = nx;
            }
        }
    }
    else if (a[y][x] == 5) {
        for (int i = 0; i < 4; i++) {
            int y_ = y;
            int x_ = x;
            while(true) {
                int ny = y_ + dy[(dir + i) % 4];
                int nx = x_ + dx[(dir + i) % 4];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 6) break;
                if (a[ny][nx] == 0) {
                    a[ny][nx] = 8;
                    v_.push_back({ny,nx});
                }
                y_ = ny;
                x_ = nx;
            }
        }
    }
    return v_;
}

void go(int idx) {
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 0) cnt++;
        ret = min(ret, cnt);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<pair<int,int>> temp = spread(idx, dir);
        go(idx + 1);
        for (auto i : temp) a[i.first][i.second] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (1 <= a[i][j] && a[i][j] <= 5) cctv.push_back({i,j});
        }
    }    
 
    go(0);
    cout << ret << "\n";
}
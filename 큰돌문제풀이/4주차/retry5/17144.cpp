#include<bits/stdc++.h>
using namespace std;
const int dy2[] = {0, 1, 0, -1}; // 우 하 좌 상
const int dx2[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1}; // 우 상 좌 하
const int dx[] = {1, 0, -1, 0};
int r, c, t, a[54][54], temp[54][54], ret;
vector<pair<int,int>> clean;

void spread() {
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] <= 0) continue; // 미세먼지가 없거나 공기청정기일 때
            int cnt = 0;
            for (int dir = 0; dir < 4; ++dir) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (a[ny][nx] == -1) continue;
                temp[ny][nx] += (a[i][j] / 5);
                ++cnt;
            }
            temp[i][j] += (a[i][j] - cnt * (a[i][j] / 5)); 
        }
    }
    memcpy(a, temp, sizeof(temp));
    for (auto& c : clean)
        a[c.first][c.second] = -1;
}

void operate(int y, int x, const int dy[], const int dx[]) {
    vector<pair<int,int>> v;
    int y_ = y;
    int x_ = x;
    int idx = 0;
    for (int dir = 0; dir < 4; ++dir) {
        while (true) {
            int ny = y_ + dy[dir];
            int nx = x_ + dx[dir];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) break;
            if (ny == y && nx == x) break;
            y_ = ny, x_ = nx;
            v.push_back({y_, x_});
        }
    }

    for (int i = v.size() - 1; i > 0; --i)
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    a[v[0].first][v[0].second] = 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> t;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == -1) clean.push_back({i,j});
        }

    while(t--) {
        spread();
        operate(clean[0].first, clean[0].second, dy, dx);
        operate(clean[1].first, clean[1].second, dy2, dx2);
    }

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            ret += a[i][j];
    cout << ret + 2 << "\n";
}
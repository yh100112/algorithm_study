#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0}; // 상 우 하 좌
const int dx[] = {0,1,0,-1};
int n, k, a[104][104], y, x, l, idx = 1, visited[104][104], cnt, rotate_idx;
string c;
vector<pair<int,string>> v;
queue<pair<int,int>> q;

void go(int y, int x) {
    ++cnt;
    int ny = y + dy[idx];
    int nx = x + dx[idx];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
        return;
    visited[ny][nx] = 1;
    q.push({y,x});
    if (a[ny][nx] == 1) {
        a[ny][nx] = 0;
    }
    else {
        visited[q.front().first][q.front().second] = 0;
        q.pop();
    }
    
    if (rotate_idx < v.size() && v[rotate_idx].first == cnt) {
        if (v[rotate_idx].second == "D") idx++;
        else                             idx--;
        idx = (idx + 4) % 4;
        rotate_idx++;
    }
    go(ny, nx);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> y >> x;
        a[--y][--x] = 1; // 사과
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
        cin >> x >> c;
        v.push_back({x,c});
    }
    
    visited[0][0] = 1;
    go(0, 0);
    cout << cnt << "\n";
}
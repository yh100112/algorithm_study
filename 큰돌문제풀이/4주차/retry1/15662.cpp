#include<bits/stdc++.h>
using namespace std;
int t, k, a[1004][8], visited[1004], ret, n, m;
string s;
vector<pair<int,int>> v; // 톱니바퀴 번호, 방향

void go(int wheel_num, int dir) {
    if (visited[wheel_num]) return;
    visited[wheel_num] = 1;

    if (wheel_num > 0 && a[wheel_num - 1][2] != a[wheel_num][6])
        go(wheel_num - 1, dir == 1 ? -1 : 1);
    if (wheel_num < t - 1 && a[wheel_num + 1][6] != a[wheel_num][2])
        go(wheel_num + 1, dir == 1 ? -1 : 1);

    if (dir == -1)
        rotate(a[wheel_num], a[wheel_num] + 1, a[wheel_num] + 8);
    else
        rotate(a[wheel_num], a[wheel_num] + 7, a[wheel_num] + 8);
}

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        for (int j = 0; j < s.length(); ++j)
            a[i][j] = s[j] - '0'; // 12시 방향부터 시계방향 순서대로 주어짐 - n극 : 0, s극 : 1
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n >> m; // 1 : 시계방향, -1 : 반시계방향
        --n;
        v.push_back({n, m});
    }

    // 회전 명령
    for (int i = 0; i < k; ++i) {
        fill(&visited[0], &visited[0] + 1004, 0);
        go(v[i].first, v[i].second);
    }

    for (int i = 0; i < t; ++i) {
        if (a[i][0] == 1)
            ret++;
    }
    
    cout << ret << "\n";
}
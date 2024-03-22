#include<bits/stdc++.h>
using namespace std;
int n, m, h, a, b, use[32][12], ret = INT_MAX;

bool check() {
    for (int i = 1; i <= n; ++i) { // 세로선 ( 열 )
        int start = i;
        for (int j = 1; j <= h; ++j) { // 놓을 수 있는 가로선 위치 ( 행 )
            if (use[j][start]) start++;
            else if (use[j][start - 1]) start--;
        }
        if (start != i)
            return false;
    }
    return true;
}

void go(int here, int cnt) {
    if (cnt >= ret || cnt > 3) return;
    if (check()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = here; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            if (use[i][j] || use[i][j - 1] || use[i][j + 1]) continue;
            use[i][j] = 1;
            go(i, cnt + 1);
            use[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        use[a][b] = 1; // b ~ b+1 세로선 사이에 있는 a번 점선 위치에 가로선 있음
    }

    go(1, 0);
    cout << ((ret == INT_MAX) ? -1 : ret) << endl;
}

/*
1. 사다리가 해당 위치에서 어디로 가는지 체크하는 함수
2. 사다리를 놓는 함수 ( 백트래킹?으로 해야함 -> 조합이므로 300C3)
*/
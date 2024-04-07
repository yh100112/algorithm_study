#include<bits/stdc++.h>
using namespace std;
int n, m, h, a, b, arr[34][34], ret = INT_MAX;

bool check() {
    for (int i = 1; i <= n; i++) { // h : 세로선마다 가로선을 놓을 수 있는 위치의 개수
        int start = i;
        for (int j = 1; j <= h; j++) {
            if (arr[j][start]) start++;
            else if (arr[j][start - 1]) start--;
        }
        if (i != start) return false;
    }
    return true;
}

void go(int here, int cnt) {
    if (cnt > 3 || cnt >= ret) return;
    if (check()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = here; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            if(arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
            arr[i][j] = 1;
            go(i, cnt + 1);
            arr[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = 1; // b ~ b + 1 세로선의 a행 위치에 가로선 놓음
    }
    go(1, 0);
    cout << (ret == INT_MAX ? -1 : ret) << "\n";
}
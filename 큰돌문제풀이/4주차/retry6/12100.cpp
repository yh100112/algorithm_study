#include<bits/stdc++.h>
using namespace std;
int n, ret = INT_MIN;
struct A {
    int a[24][24];
    void pushing() {
        for (int i = 0; i < n; i++) {
            int temp[n];
            fill(temp, temp + n, 0);
            int c = -1, d = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) continue;
                if (d && temp[c] == a[i][j]) temp[c] *= 2, d = 0;
                else temp[++c] = a[i][j], d = 1;
            }
            for (int j = 0; j < n; j++)
                a[i][j] = temp[j];
        }
    }
    void rotate() {
        int temp[24][24];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[i][j] = a[n - j - 1][i];
        memcpy(a, temp, sizeof(temp));
    }
    int check() {
        int mx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, a[i][j]);
        return mx;
    }
};

void go(int cnt, A ori) {
    if (cnt == 5) {
        ret = max(ret, ori.check());
        return;
    }

    for (int i = 0; i < 4; i++) {
        A d = ori;
        d.pushing();
        go(cnt + 1, d);
        ori.rotate();
    }
}

int main() {
    cin >> n;
    A c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c.a[i][j];
    
    go(0, c);    
    cout << ret << "\n";
}
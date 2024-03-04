#include<bits/stdc++.h>
using namespace std;
int n, m, b, a[504][504], height, mn = 987654321;

int main(){
    cin >> n >> m >> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int h = 0; h <= 256; ++h) {
        int add = 0;   // 인벤토리에서 꺼내서 블록 추가
        int erase = 0; // 블록 제거
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] > h)
                    erase += (a[i][j] - h);
                else if (a[i][j] < h) 
                    add += (h - a[i][j]);
            }
        }

        int t = 0;
        if (b + erase >= add) {
            t = erase * 2 + add;
            if (t <= mn) {
                mn = t;
                height = h;
            }
        }
    }

    cout << mn << ' ' << height << "\n";
}
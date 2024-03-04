#include<bits/stdc++.h>
using namespace std;
int num, a[102][102], ret, n, m;

int main(){
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> n >> m;
        for (int j = n; j < n + 10; ++j)
            for (int k = m; k < m + 10; ++k)
                a[j][k] = 1;
    }

    for (int i = 0; i < 102; ++i) {
        for (int j = 0; j < 102; ++j) {
            if (a[i][j]) ++ret;
        }
    }
    cout << ret << "\n";
}
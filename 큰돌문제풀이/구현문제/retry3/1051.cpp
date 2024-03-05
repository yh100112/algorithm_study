#include<bits/stdc++.h>
using namespace std;
int n, m, a[52][52], ret = -987654321;
string s;

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int len = 0;
            while (i + len < n && j + len < m) {
                bool check = true;
                if (a[i][j] != a[i][j + len]) check = false;
                if (a[i][j] != a[i + len][j]) check = false;
                if (a[i][j] != a[i + len][j + len]) check = false;
                if (check)
                    ret = max(ret, (len + 1) * (len + 1));
                ++len;
            }
        }
    }
    cout << ret << "\n";
}
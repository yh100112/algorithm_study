#include<bits/stdc++.h>
using namespace std;
bool check[2504] = {0};
int cnt[2504], ret = -987654321;
string s, db = "quack";

int main(){
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'q') {
            int db_idx = 0;
            int cur = i;
            while (db_idx < db.length() && cur < s.length()) {
                if (s[cur] == db[db_idx] && check[cur] == 0) {
                    check[cur] = 1;
                    ++db_idx;
                }
                ++cnt[cur++];
            }
            if (db_idx < db.length()) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        if (cnt[i] == 0) {
            cout << -1 << "\n";
            return 0;
        }
        ret = max(ret, cnt[i]);
    }
    cout << ret << "\n";
}
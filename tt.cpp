#include<bits/stdc++.h>
using namespace std;
int cnt[2504], used[2504], flag, ret = INT_MIN;
string s, db = "quack";

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'q') continue;
        int idx = 0;
        int j = i;
        while(true) {
            if (idx == 5 || j == s.length()) break;
            if (db[idx] == s[j] && !used[j]) {
                used[j] = 1;
                idx++;
            }
            cnt[j]++;
            j++;
        }
        if (idx != 5) flag = 1;
    }
    for (int i = 0; i < s.length(); i++) {
        if (cnt[i] == 0) flag = 1;
        ret = max(cnt[i], ret);
    }
    if (flag) cout << -1 << "\n";
    else cout << ret << "\n";
}
#include<bits/stdc++.h>
using namespace std;
int num, n;
string s1, s2;
map<string, int> m;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        m.clear();
        cin >> num;
        for (int j = 0; j < num; ++j) {
            cin >> s1 >> s2;
            m[s2]++;
        }
        int ans = 1;
        for (auto& m_ : m)
            ans *= (m_.second + 1);
        --ans;
        cout << ans << "\n";
    }
}
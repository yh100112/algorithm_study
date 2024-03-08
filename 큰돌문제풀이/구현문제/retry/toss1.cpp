#include<bits/stdc++.h>
using namespace std;
int n;
set<int> se;
string s, ret;
vector<string> v;

int main(){
    cin >> s >> n;
    for (int i = 0; i <= s.length() - n; ++i) {
        for (int j = i; j < i + n; ++j) {
            if (s[j] - '0' > n)
                break;
            se.insert(s[j] - '0');
            ret += s[j];
        }
        if (se.size() == n)
            v.push_back(ret);
        ret = "";
        se.clear();
    }
    sort(v.begin(), v.end(), [](string& left, string& right){
        return left > right;
    });

    if (v.size())
        cout << v.front() << "\n";
    else
        cout << -1 << "\n";
}
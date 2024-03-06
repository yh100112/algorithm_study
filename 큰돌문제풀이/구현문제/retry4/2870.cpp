#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;

void check(string ret) {
    while(ret.length() && ret.front() == '0')
        ret.erase(ret.begin());
    if (ret.size() == 0) ret += "0";
    v.push_back(ret);
}

void go() {
    string ret = "";
    for (int j = 0; j < s.length(); ++j) {
        if ('0' <= s[j] && s[j] <= '9')
            ret += s[j];
        else {
            if (ret.size()) {
                check(ret);
                ret = "";
            }
        }
    }
    if (ret.size())
        check(ret);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        go();
    }

    sort(v.begin(), v.end(), [](string& left, string& right){
        if (left.size() == right.size())
            return left < right;
        else
            return left.size() < right.size();
    });
    for (auto& i : v)
        cout << i << "\n";
}
#include<bits/stdc++.h>
using namespace std;
string s, bomb;
stack<char> st;

int main() {
    cin >> s >> bomb;
    string ret = "";
    int bomb_l = bomb.length();
    for (int i = 0; i < s.length(); ++i) {
        ret += s[i];
        int ret_l = ret.length();
        if (ret.size() >= bomb.size() && ret.substr(ret_l - bomb_l) == bomb) {
            ret.erase(ret_l - bomb_l);
        }
    }
    if (ret.size())
        cout << ret << "\n";
    else
        cout << "FRULA" << "\n";
}
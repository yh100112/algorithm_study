#include<bits/stdc++.h>
using namespace std;
string s, a, ret;

int main(){
    cin >> s >> a;
    for(int i = 0; i < s.size(); i++){
        ret += s[i];
        if(ret.size() >= a.size() && ret.substr(ret.size() - a.size()) == a){
            ret.erase(ret.size() - a.size());
        }
    }
    if(ret.size()) cout << ret << '\n';
    else cout << "FRULA" << '\n';
}
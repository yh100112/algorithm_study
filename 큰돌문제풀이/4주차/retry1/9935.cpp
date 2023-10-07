#include<bits/stdc++.h>
using namespace std;
string s, bomb, ret;

int main(){
    cin >> s >> bomb;
    for(int i = 0; i < s.size(); i++){
        ret += s[i];
        if(ret.size() >= bomb.size() && ret.substr(ret.size() - bomb.size()) == bomb)
            ret.erase(ret.size() - bomb.size());
    }
    if(!ret.size()) cout << "FRULA" << '\n';
    else cout << ret << '\n';
}
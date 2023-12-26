#include<bits/stdc++.h>
using namespace std;
int R, idx, ret, used[2504], cnt[2504];
string s, DB = "quack";

int main(){
    cin >> s;
    bool result = true;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != 'q') continue;
        R = i, idx = 0;
        while(R < s.size() && idx < 5){
            if(!used[R] && s[R] == DB[idx]){
                used[R] = 1;
                idx++;
            }
            R++;
        }
        if(idx != 5) result = false;
        for(int j = i; j < R; j++)
            cnt[j]++;
    }

    for(int i = 0; i < s.size(); i++){
        ret = max(ret, cnt[i]);
        if(cnt[i] == 0)
            return false;
    }

    if(result) cout << ret << '\n';
    else cout << -1 << '\n';
}
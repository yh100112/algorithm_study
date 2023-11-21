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
        // "quack"을 뽑아낸다.
        while(R < s.size() && idx < 5){
            if(!used[R] && s[R] == DB[idx]){
                used[R] = 1;
                idx++;
            }
            R++; // 문자열 s를 순차적으로 옆으로 이동하면서 체크
        }
        if(idx != 5) result = false; // 끝까지 다 돌았는데 "quack"이 완성되지 않음 -> 잘못된 울음소리
        for(int j = i; j < R; j++) // 오리의 최소개수 구하기
            cnt[j]++;
    }

    for(int i = 0; i < s.size(); i++){
        ret = max(ret, cnt[i]);
        if(cnt[i] == 0)
            result = false;
    }

    if(result) cout << ret << '\n';
    else cout << -1 << '\n';
}
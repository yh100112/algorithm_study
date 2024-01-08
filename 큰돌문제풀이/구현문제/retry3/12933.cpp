#include<bits/stdc++.h>
using namespace std;
string s, db = "quack";
int ret = -987654321, cnt[2504], visited[2504];

int main(){
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != 'q') continue;
        int idx = 0;
        int j = i; // q 위치 -> 여기부터 quack 로 단어가 완성될 때까지 이동        
        while(j < s.size() && idx < db.size()){
            if(!visited[j] && s[j] == db[idx]){
                idx++;
                visited[j] = 1;
            }
            cnt[j]++;
            j++;
        }
        if(idx < db.size()) flag = false;
    }

    for(int i = 0; i < s.size(); i++)
        if(cnt[i] == 0)
            flag = false;
    
    if(!flag) cout << -1 << '\n';
    else {
        for(int i = 0; i < s.size(); i++)
            ret = max(ret, cnt[i]);
        cout << ret << '\n';
    }
}
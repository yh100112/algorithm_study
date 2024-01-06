#include<bits/stdc++.h>
using namespace std;
string s, db = "quack";
int visited[2504], cnt[2504], ret = -987654321;
bool flag = true, in = false;

int main(){
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] != 'q') continue;
        in = true;
        int j = i, idx = 0;
        while(j < s.size() && idx < db.size()){
            if(!visited[j] && s[j] == db[idx]){
                visited[j] = 1;
                ++idx;
            }
            ++cnt[j];
            ++j;
        }
        if(idx < db.size()) flag = false;
    }

    // quackkkkquack 같은 건 kkk부분을 그냥 넘어가버리고 뒤에 quack를 체크하기 때문에 in과 flag에 모두 
    // 걸리지 않아서 답이 -1이 나와야 하는데 flag와 in에 걸리지 않아서 -987654321이 나온다. 그래서 이부분이 필요
    for(int i = 0; i < s.size(); i++){
        ret = max(ret, cnt[i]);
        if(cnt[i] == 0)
            flag = false;
    }

    if (!flag || !in) cout << -1 << '\n';
    else {
        cout << ret << '\n';
    }
}
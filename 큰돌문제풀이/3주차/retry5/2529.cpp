#include<bits/stdc++.h>
using namespace std;
int k, visited[10];
vector<char> oper;
vector<string> ret;

bool check(char a, int b, int c){
    if(a == '>') return b > c;
    if(a == '<') return b < c;
}

void go(int idx, string s){
    if(idx == k + 1){
        ret.push_back(s);
        return;
    }

    for(int i = 0; i <= 9; i++){
        if(visited[i]) continue;
        if(idx == 0 || check(oper[idx - 1], s[idx - 1] - '0', i)){
            visited[i] = 1;
            go(idx + 1, s + to_string(i));
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> k;
    oper.resize(k);
    for(int i = 0; i < k; i++)
        cin >> oper[i];
    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n' << ret[0] << '\n';
}
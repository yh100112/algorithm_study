#include<bits/stdc++.h>
using namespace std;
int k, visited[10];
char oper[10];
vector<string> ret;

bool check(char a, char b, char c){
    if(a == '<' && b < c) return true;
    if(a == '>' && b > c) return true;
    return false;
}


void go(int idx, string num){
    if(idx == k + 1){
        ret.push_back(num);
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(visited[i]) continue;
        if(idx == 0 || check(oper[idx - 1], num[idx - 1], i + '0')){
            visited[i] = 1;
            go(idx + 1, num + to_string(i));
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> oper[i];
    }
    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << " " << ret[0] << "\n";
}

#include<bits/stdc++.h>
using namespace std;
int k;
char oper[10], visited[10];
vector<string> v;


bool check(char a, int b, int c){
    if(a == '>') return b > c;
    if(a == '<') return b < c;
    return false;
}

void go(int idx, string s){
    if(idx == k + 1){
        v.push_back(s);
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(!visited[i]){
            if(idx == 0 || check(oper[idx - 1], s[idx - 1] - '0', i)){
                visited[i] = 1;
                go(idx + 1, s + to_string(i));
                visited[i] = 0;
            }
        }
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> oper[i];
    go(0, "");
    sort(v.begin(), v.end());

    cout << v[v.size() - 1] << '\n';
    cout << v[0] << '\n';
}
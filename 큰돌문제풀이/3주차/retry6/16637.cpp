#include<bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string s;
vector<int> num, oper;

int cal(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}

void go(int idx, int sum){
    if(idx == num.size() - 1){
        ret = max(ret, sum);
        return;
    }

    go(idx + 1, cal(oper[idx], sum, num[idx + 1]));
    if(idx + 2 < num.size()){
        int temp = cal(oper[idx + 1], num[idx + 1], num[idx + 2]);
        go(idx + 2, cal(oper[idx], sum, temp));
    }
}

int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret << '\n';
}
#include<bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper_str;
int n, ret = INT_MIN;
string s;

int oper(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}

void go(int here, int _num){
    cout << here << " " << _num << "\n";
    if(here == num.size() - 1){
        ret = max(ret, _num);
        cout << "완료 : " << _num << "\n"; 
        return;
    }

    go(here + 1, oper(oper_str[here], _num, num[here + 1]));
    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);    
    }
    go(0, num[0]);
    return 0;
}
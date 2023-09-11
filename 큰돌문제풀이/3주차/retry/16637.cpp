#include<bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string s;
vector<int> num;
vector<char> oper_ptr;

int cal(char o, int a, int b){
    if(o == '+') return a + b;
    if(o == '-') return a - b;
    if(o == '*') return a * b;
}

void go(int idx, int _num){
    if(idx == num.size() - 1){
        ret = max(ret, _num);
        return;
    }

    go(idx + 1, cal(oper_ptr[idx], _num, num[idx+1])); // 앞에부터 계산
    if(idx + 2 <= num.size() - 1){ // 뒤부터 계산
        int temp = cal(oper_ptr[idx+1], num[idx+1], num[idx+2]); // 뒤계산
        go(idx+2, cal(oper_ptr[idx], _num, temp)); // 뒤와 앞 계산
    }
}

int main(){
    cin >> n;
    cin >> s; 
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_ptr.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret << "\n";
}
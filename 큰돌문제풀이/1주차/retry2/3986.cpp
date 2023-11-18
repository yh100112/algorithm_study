#include<bits/stdc++.h>
using namespace std;
int n, cnt;
string str;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        stack<int> s;
        for(int j = 0; j < str.size(); j++){
            if(s.size() && s.top() == str[j])
                s.pop();
            else
                s.push(str[j]);
        }
        if(!s.size()) cnt++;
    }
    cout << cnt << '\n';
}
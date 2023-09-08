#include<bits/stdc++.h>
using namespace std;
int t;
string a;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a;
        stack<char> s;
        for(int j = 0; j < a.size(); j++){
            if (s.empty())
                s.push(a[j]);
            else {
                if(s.top() == '('){
                    if(a[j] == ')') s.pop();
                    else s.push(a[j]);
                }
                else{
                    s.push(a[j]);
                }
            }
        }
        if (s.size() != 0) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}
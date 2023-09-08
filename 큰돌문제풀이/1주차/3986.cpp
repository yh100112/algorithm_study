#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            if(st.size() != 0 && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        if(st.empty()) cnt++;
    }
    cout << cnt << "\n";
}
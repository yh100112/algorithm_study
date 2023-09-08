#include<bits/stdc++.h>
using namespace std;
int n, cnt;
string str;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        stack<int> st;
        for(int j = 0; j < str.length(); j++){
            if(!st.empty() && st.top() == str[j]){
                st.pop();
            } 
            else {
                st.push(str[j]);
            }
        }
        if(st.empty()) cnt++; 
    }
    cout << cnt;
}
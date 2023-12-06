#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
    while(true){
        getline(cin ,s);
        if(s == ".") break; // 종료조건
        stack<int> st;
        bool flag = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(st.size() && st.top() == '(') st.pop();
                else {
                    flag = 1;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(st.size() && st.top() == '[') st.pop();
                else {
                    flag = 1; 
                    break;
                }
            }
            else if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
        }
        if(st.size() || flag) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
}
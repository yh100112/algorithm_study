#include<bits/stdc++.h>
using namespace std;
string s, ret;
stack<char> st;

int main(){
    getline(cin, s);
    bool flag = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '<'){
            if(st.size()){
                while(st.size()){
                    ret += st.top();
                    st.pop();
                }
            }
            flag = true;
            ret += '<';
        }
        else if(s[i] == '>'){
            flag = false;
            ret += s[i];
        }
        else if(s[i] == ' '){
            while(st.size()){
                ret += st.top();
                st.pop();
            }
            ret += ' ';
        }
        else if(!flag){
            st.push(s[i]);
        }
        else{
            ret += s[i];
        }
    }
    if(st.size()){
        while(st.size()){
            ret += st.top();
            st.pop();
        }
    }

    cout << ret << '\n';
}
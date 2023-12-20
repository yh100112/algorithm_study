#include<bits/stdc++.h>
using namespace std;
string s, ret;
stack<char> st;

void print(){
    while(!st.empty()){
        ret += st.top();
        st.pop();
    }
}

int main(){
    getline(cin, s);
    bool tag = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<'){
            print();
            ret += s[i];
            tag = true;
        }
        else if(s[i] == '>'){
            ret += s[i];
            tag = false;
        }
        else if(tag){
            ret += s[i];
        }
        else{
            if(s[i] == ' '){
                print();
                ret += s[i];
            }
            else{
                st.push(s[i]);
            }
        }
    }
    print();
    cout << ret << '\n';
}
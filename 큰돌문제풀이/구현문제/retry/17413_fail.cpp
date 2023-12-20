#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
    getline(cin, s);
    stack<int> st;
    int start = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<'){
            st.push(s[i]);
        }
        else if(s[i] == '>'){
            if(st.size() && st.top() == '<') 
                st.pop();
        }
        else if(!st.size()){
            if(start == -1 && s[i] != ' '){
                start = i;
            }
            else if(s[i] == ' '){
                start = -1;
            }
            else if(i + 1 < s.length() - 1){
                if(s[i + 1] == '<' || s[i + 1] == ' '){
                    reverse(s.begin() + start, s.begin() + i + 1);
                    start = -1;
                }
            }
        }
    }
    if(start != -1)
        reverse(s.begin() + start, s.begin() + s.length());
    cout << s << '\n';
}
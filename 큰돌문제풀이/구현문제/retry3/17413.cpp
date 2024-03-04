#include<bits/stdc++.h>
using namespace std;
bool tag = false;
string s;
stack<char> st;

int main(){
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '<') {
            while(st.size()){
                cout << st.top();
                st.pop();
            }
            tag = true;
            cout << "<";
        }
        else if (s[i] == '>') {
            tag = false;
            cout << ">";
        }
        else if (tag == true) {
            cout << s[i];
        }
        else if (s[i] != ' ') {
            st.push(s[i]);
        }
        else if (s[i] == ' ') {
            while(st.size()){
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
    }    
    while(st.size()){
        cout << st.top();
        st.pop();
    }
}
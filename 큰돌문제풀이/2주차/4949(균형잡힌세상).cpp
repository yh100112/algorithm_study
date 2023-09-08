#include<bits/stdc++.h>
using namespace std;
string a;

int main(){
    while(true){
        string s;
        getline(cin, s);
        if(s == ".") break;
        stack<char> st;
        bool check = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(st.size() == 0 || st.top() == '['){
                    check = false;
                    break;
                }
                else{
                    st.pop();
                }
            }
            else if(s[i] == ']'){
                if(st.size() == 0 || st.top() == '('){
                    check = false;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
        }
        if(check && st.size() == 0) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}

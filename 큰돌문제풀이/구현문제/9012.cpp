#include<bits/stdc++.h>
using namespace std;
int n;
string str;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        stack<int> st;
        for(int j = 0; j < str.size(); j++){
            if(st.size()){
                if(st.top() == '(' && str[j] == ')')
                    st.pop();
                else
                    st.push(str[j]);
            }
            else
                st.push(str[j]);
        }
        if(st.size()) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
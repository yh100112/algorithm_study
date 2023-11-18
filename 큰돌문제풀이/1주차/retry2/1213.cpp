#include<bits/stdc++.h>
using namespace std;
string s, ret;
stack<char> st;
vector<char> v;


int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        v.push_back(s[i]);
    sort(v.begin(), v.end());

    for(auto i : v){
        if(st.size() && st.top() == i)
            st.pop();
        else
            st.push(i);
    }

    if(st.size() <= 1){
        if(st.size() % 2 == 1)
            ret += st.top();
        for(int i = v.size() - st.size() - 1; i > 0; i -= 2){
            ret += v[i];
            ret = v[i] + ret;
        }
        cout << ret << '\n';
    }
    else{
        cout << "I'm Sorry Hansoo" << '\n';
    }
}
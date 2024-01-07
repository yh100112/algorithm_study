#include<bits/stdc++.h>
using namespace std;
int n, a[1000004], c[1000004];
stack<int> st;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    fill(&c[0], &c[0] + 1000004, -1);
    for(int i = 0; i < n; i++){
        while(st.size() && a[st.top()] < a[i]){
            c[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++)
        cout << c[i] << ' ';
    cout << '\n';
}
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int n, num, ret[1000002], a[1000002];


int main() {
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> num; 
        a[i] = num;
    }

    fill(&ret[0], &ret[0] + 1000002, -1);
    for (int i = 0; i < n; ++i) {
        while(st.size() && a[st.top()] < a[i]) {
            ret[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; ++i)
        cout << ret[i] << ' ';
    cout << "\n";
}
#include<bits/stdc++.h>
using namespace std;
int n, a[1000002], ret[1000002];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    fill(&ret[0], &ret[0] + 1000002, -1);

    stack<int> s;
    for(int i = 0; i < n; i++){
        int temp = i - 1;
        while(s.size() && s.top() < a[i]){
            ret[temp] = a[i];
            --temp;
            s.pop();
        }
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++)
        cout << ret[i] << ' ';
    cout << '\n';
}
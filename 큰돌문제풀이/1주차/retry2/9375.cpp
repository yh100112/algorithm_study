#include<bits/stdc++.h>
using namespace std;
int n, k;
map<string, int> m;

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> n;
        string name, kind;
        int cnt = 1;
        m.clear();
        for(int i = 0; i < n; i++){
            cin >> name >> kind;
            m[kind]++;    
        }
        for(auto i : m)
            cnt *= (i.second + 1);
        cnt -= 1;
        cout << cnt << '\n';
    }
}
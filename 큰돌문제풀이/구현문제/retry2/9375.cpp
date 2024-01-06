#include<bits/stdc++.h>
using namespace std;
int m, n;
string a, b;

int main(){
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;

        int ret = 1;
        map<string,int> m;
        for(int j = 0; j < n; j++){
            cin >> a >> b;
            m[b]++;
        }

        for(auto& m_ : m)
            ret *= (m_.second + 1);
        
        cout << ret - 1 << '\n';
    }
}
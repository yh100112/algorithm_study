#include<bits/stdc++.h>
using namespace std;
string a, b;
int cnt, n, ret;
map<string, int> m;

int main(){
    cin >> cnt;
    while(cnt--){
        cin >> n;
        m.clear();
        ret = 1;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            m[b]++;
        }
        for(auto i : m)
            ret *= (i.second + 1);
        ret--;    
        cout << ret << '\n';
    }
}
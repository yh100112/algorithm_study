#include<bits/stdc++.h>
using namespace std;
int n, m;
string q, c;
map<string, int> a;
map<int,string> b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> c;
        a.insert({c, i+1});
        b.insert({i+1,c});
    }
    for(int i = 0; i < m; i++){
        cin >> q;
        if (atoi(q.c_str()) == 0) {
            cout << a[q] << "\n";        
        }
        else {
            cout << b[atoi(q.c_str())] << "\n";
        }
    }
}
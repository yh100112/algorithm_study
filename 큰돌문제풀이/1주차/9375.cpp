#include<bits/stdc++.h>
using namespace std;
int test, n;
string a,b;
int main(){
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> n;
        map<string, int> m;
        for(int j = 0; j < n; j++){
            cin >> a >> b;
            m[b]++;
        }
        long long ret = 1;
        for(auto v : m){
            ret *= ((long long)v.second + 1);
        }
        ret--;
        cout << ret << "\n";
    }
}
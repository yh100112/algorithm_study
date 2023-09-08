#include<bits/stdc++.h>
using namespace std;
int test, n;
string a,b;

int main(){
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> n;
        map<string,int> m1;
        for(int j = 0; j < n; j++){
            cin >> a >> b;
            if(m1.find(b) != m1.end()) m1[b]++;
            else m1[b] = 1;
        }
        int ret = 1;
        for(auto v: m1) {
            ret = ret * (v.second + 1);
        }
        cout << ret - 1 << "\n";
    }
}
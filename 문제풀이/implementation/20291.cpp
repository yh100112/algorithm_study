#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    map<string,int> m;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        string ext = s.substr(s.find('.') + 1);
        m[ext]++;
    }
    for(auto v: m){
        cout << v.first << " " << v.second << "\n";
    }
}
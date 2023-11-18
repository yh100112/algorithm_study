#include<bits/stdc++.h>
using namespace std;
int n;
string pattern, s;

int main(){
    cin >> n >> pattern;
    for(int i = 0; i < n; i++){
        cin >> s;
        string l, r;
        l = pattern.substr(0, pattern.find('*'));
        r = pattern.substr(pattern.find('*') + 1);
        if(s.size() < l.size() + r.size()){
            cout << "NE" << '\n';
            continue;
        }
        if(s.substr(0, l.size()) == l && s.substr(s.size() - r.size()) == r){
            cout << "DA" << '\n';
        }
        else
            cout << "NE" << '\n';
    }
}
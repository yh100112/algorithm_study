#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin >> s;
    string a = s;
    reverse(s.begin(),s.end());
    if(s == a) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}
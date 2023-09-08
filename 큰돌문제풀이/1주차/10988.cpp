#include<bits/stdc++.h>
using namespace std;
string str;

int main(){
    cin >> str;
    string ori = str;
    reverse(str.begin(), str.end());
    if (ori == str) cout << 1 << "\n";
    else cout << 0 << "\n";     
}
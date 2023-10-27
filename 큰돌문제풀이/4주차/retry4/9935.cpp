#include<bits/stdc++.h>
using namespace std;
string s, bomb, temp;

int main(){
    cin >> s;
    cin >> bomb;

    for(int i = 0; i < s.length(); i++){
        temp += s[i];
        if(temp.size() >= bomb.size() && temp.substr(temp.size() - bomb.size()) == bomb)
            temp.erase(temp.size() - bomb.size());
    }
    if(temp.size()) cout << temp << '\n';
    else cout << "FRULA" << '\n';
}
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 65 && s[i] < 97){
            if(s[i] + 13 > 'Z') s[i] = s[i] + 13 - 26; // 알파벳은 26개이므로 -26을 해줌
            else s[i] = s[i] + 13;
        }
        else if (s[i] >= 97 && s[i] <= 122){
            if(s[i] + 13 > 'z') s[i] = s[i] + 13 - 26;
            else s[i] = s[i] + 13;
        }
        cout << s[i];
    }
}
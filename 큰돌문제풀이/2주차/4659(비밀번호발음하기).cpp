#include<bits/stdc++.h>
using namespace std;
string s;

bool isVowel(char s){
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return true;
    return false;
}

int main(){
    while(true){
        cin >> s;
        if(s == "end") 
            break;
        int flag = 0;
        int lcnt = 0; 
        int rcnt = 0;
        bool is_include_v = 0;
        int prev = -1;
        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])) { lcnt++; rcnt = 0; is_include_v = 1; }
            else { rcnt++; lcnt = 0; }
            if(lcnt == 3 || rcnt == 3) flag = 1;
            if(i >= 1 && s[prev] == s[i] && s[i] != 'e' && s[i] != 'o') {
                flag = 1;
            }
            prev = i;
        }
        if(!is_include_v) flag = 1;
        if(flag) cout << "<" << s << "> is not acceptable." << endl;
        else cout << "<" << s << "> is acceptable." << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
    getline(cin, s);
    bool tag = false;
    int st_word = -1;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<')      tag = true;
        if(!tag && s[i] != ' ') {
            if(st_word < 0){
                st_word = i;
                cnt++;
            }
            else {
                cnt++;
                if (i + 1 == s.length()) {
                    reverse(s.begin() + st_word, s.end());
                }
                else {
                    if(s[i + 1] == ' ' || s[i + 1] == '<') {
                        reverse(s.begin() + st_word, s.begin() + st_word + cnt);
                        st_word = -1;
                        cnt = 0;
                    }
                }
            }
        }
        if(s[i] == '>') tag = false;
    }
    cout << s << "\n";
}
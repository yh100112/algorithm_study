//! 테케는 다 맞지만 히든 케이스를 통과하지 못한 풀이
// #include<bits/stdc++.h>
// using namespace std;
// string s;

// int main(){
//     getline(cin, s);
//     bool tag = false;
//     int st_word = -1;
//     int cnt = 0;
//     for(int i = 0; i < s.length(); i++){
//         if(s[i] == '<')      tag = true;
//         if(!tag && s[i] != ' ') {
//             if(st_word < 0){
//                 st_word = i;
//                 cnt++;
//             }
//             else {
//                 cnt++;
//                 if (i + 1 == s.length()) {
//                     reverse(s.begin() + st_word, s.end());
//                 }
//                 else {
//                     if(s[i + 1] == ' ' || s[i + 1] == '<') {
//                         reverse(s.begin() + st_word, s.begin() + st_word + cnt);
//                         st_word = -1;
//                         cnt = 0;
//                     }
//                 }
//             }
//         }
//         if(s[i] == '>') tag = false;
//     }
//     cout << s << "\n";
// }


#include<bits/stdc++.h>
using namespace std;
string str, ret;
stack<char> a;

int main(){
    getline(cin, str);
    bool flag = false;
    for(int i = 0; i < str.length(); i++){
       if(str[i] == '<') {
            while(!a.empty()){
                ret += a.top();
                a.pop();
            }
            flag = true;
       }
       if(flag == false) {
            if(str[i] == ' ') {
                while(!a.empty()){
                    ret += a.top();
                    a.pop();
                }
                ret += str[i];
            }
            else {
                a.push(str[i]);
            }
       }
       else {
            ret += str[i];
            if(str[i] == '>') {
                flag = false;
            }
       }
       if(i == str.length() - 1){
            while(!a.empty()){
                ret += a.top();
                a.pop();
            }
       }
    }
    cout << ret << "\n";
}
































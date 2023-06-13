#include<bits/stdc++.h>
using namespace std;
int n, ret;
string s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        bool ck[26]; 
        memset(ck, 0, sizeof(ck)); // 초기 세팅 0
        ck[s[0] - 'a'] = 1;
        bool flag = true;
        for(int i = 1; i < s.length(); i++){
            if(s[i] != s[i-1]) {
                if(ck[s[i] - 'a'] == 1) {
                    flag = false;
                    break;
                }
                else {
                    ck[s[i] - 'a'] = 1;
                }
            }
        }
        if(flag) ret++;
    }
    cout << ret << "\n";
}
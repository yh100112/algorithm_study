#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[26];
string s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cnt[*s.begin() - 97]++;
    }
    int flag = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] >= 5) {
            cout << char(97 + i);
            flag = 1;
        }
    }
    if(flag == 0) {
        cout << "PREDAJA" << "\n";
    }
}
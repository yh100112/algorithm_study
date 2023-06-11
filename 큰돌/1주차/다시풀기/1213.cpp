#include<bits/stdc++.h>
using namespace std;
string s, ret;
int arr[100], cnt;

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        arr[s[i]]++;
    }
    int a = 0;
    for(int i = 'Z'; i >= 'A'; i--){
        if (arr[i]) {
            if(arr[i] & 1) {
                for(int j = 0; j < arr[i]-1; j += 2){
                    ret = char(i) + ret;
                    ret += char(i);
                }                        
                a = i;
                cnt++;
                if(cnt == 2) {
                    cout << "I'm Sorry Hansoo" << "\n";
                    return 0;
                }
            }
            else {
                for(int j = 0; j < arr[i]; j += 2){
                    ret = char(i) + ret;
                    ret += char(i);
                }                        
            }
        }
    }
    if (a) ret.insert(ret.begin() + ret.length() / 2, char(a));
    cout << ret << "\n";
}
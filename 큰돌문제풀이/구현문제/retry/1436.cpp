#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    int i = 666;
    int cnt = 0;
    for(;;i++){
        string s = to_string(i);
        if(s.find("666") != string::npos) cnt++;
        if(cnt == n) {
            cout << i << '\n';
            break;
        }
    }
}
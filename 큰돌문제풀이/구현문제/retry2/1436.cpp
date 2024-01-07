#include<bits/stdc++.h>
using namespace std;
int n, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 666; ;++i){
        string num = to_string(i);
        if(num.find("666") != string::npos)
            cnt++;
        if(cnt == n){
            cout << i << '\n';
            break;
        }
    }
}
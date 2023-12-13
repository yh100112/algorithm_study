#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    while(cin >> n){
        ll ret = 1, cnt = 1;
        while(true){
            if(ret % n == 0){
                cout << cnt << '\n';
                break;
            }
            ret = (ret * 10 + 1) % n;
            cnt++;
        }
    }
}
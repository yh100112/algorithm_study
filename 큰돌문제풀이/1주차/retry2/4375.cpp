#include<bits/stdc++.h>
using namespace std;
long long n, num, cnt;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n){
        num = 1, cnt = 1;
        while(true){
            if(num % n == 0){
                cout << cnt << '\n';
                break;
            }
            num = (num * 10 + 1) % n;
            cnt++;
        }
    }
}
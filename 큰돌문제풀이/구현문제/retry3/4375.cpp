#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(cin >> n){
        int cnt = 0;
        long long num = 1;
        while(true){
            ++cnt;
            if(num % n == 0){
                cout << cnt << "\n";
                break;
            }
            num = (num * 10 + 1) % n;
        }
    }
}
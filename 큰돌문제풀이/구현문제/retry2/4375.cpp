#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt; 
int n;

int main(){
    while(cin >> n){
        ll a = 1;
        cnt = 1;
        while(a % n != 0){
            cnt++;
            a = (a * 10 + 1) % n;
        }
        cout << cnt << '\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
int t, n;
long long ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        long long two = 0, five = 0;
        for(int j = 2; j <= n; j *= 2){
            two += (n / j);
        }

        for(int j = 5; j <= n; j *= 5){
            five += (n / j);
        }

        ret = min(two, five);
        cout << ret << '\n';
    }
}
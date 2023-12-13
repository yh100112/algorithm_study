#include<bits/stdc++.h>
using namespace std;
long long t, n, two, five;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        long long a = 2;
        long long b = 5;
        two = 0, five = 0;
        while(a <= n){
            two += (n / a);
            a *= 2; 
        }
        while(b <= n){
            five += (n / b);
            b *= 5; 
        }
        cout << min(two, five) << '\n';
    }
}
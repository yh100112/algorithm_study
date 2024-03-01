#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t, f;
ll a;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        t = f = 0;
        for(int j = 1; j <= a; ++j){
            int num = j;
            while(num % 2 == 0){
                num = num / 2;
                ++t;
            }
            num = j;
            while(num % 5 == 0){
                num = num / 5;
                ++f;
            }
        }
        cout << min(t,f) << "\n";
    }
}
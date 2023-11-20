#include<bits/stdc++.h>
using namespace std;
int t,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int ret2 = 0, ret5 = 0;
        for(int a = 2; a <= n; a *= 2){
            ret2 += n / a;
        }
        for(int a = 5; a <= n; a *= 5){
            ret5 += n / a;
        }
        cout << min(ret2, ret5) << "\n";
    }
}
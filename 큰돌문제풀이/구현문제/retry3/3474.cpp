#include<bits/stdc++.h>
using namespace std;
int cnt, n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> cnt;
    for(int i = 0; i < cnt; ++i){
        cin >> n;
        int two = 0, five = 0;
        for(int j = 2; j <= n; j *= 2)
            two += (n / j);
        for(int j = 5; j <= n; j *= 5)
            five += (n / j);
        cout << min(two, five) << "\n";
    }
}
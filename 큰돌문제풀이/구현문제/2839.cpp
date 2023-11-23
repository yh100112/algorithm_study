#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF;

int main() {
    cin >> n;
    if(n % 3 == 0) ret = min(ret, n / 3);
    if(n % 5 == 0) ret  = min(ret, n / 5);

    for(int i = 3; i <= n; i += 3){
        int a = n - i; // 5
        if(a % 5 == 0)
            ret = min(ret, a / 5 + i / 3);
    }
    if(ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';
}

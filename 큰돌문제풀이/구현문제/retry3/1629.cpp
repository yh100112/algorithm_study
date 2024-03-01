#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;

ll go(ll a, ll b, ll c) {
    if (b == 1) return a % c;

    ll ret = go(a, b / 2, c);
    ret = (ret * ret) % c;
    if (b % 2 != 0) ret = ret * a % c;
    return ret;
}

int main(){
    cin >> a >> b >> c;
    cout << go(a,b,c) << "\n";    
}
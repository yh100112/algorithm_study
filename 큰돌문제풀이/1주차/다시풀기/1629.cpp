#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;

ll go(ll a, ll b){
    if(b == 1) return a % c;

    ll ret = go(a,b/2); // a % c
    ret = (ret * ret) % c;
    if(b & 1) return (ret * a) % c;
    return ret % c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a,b);
}
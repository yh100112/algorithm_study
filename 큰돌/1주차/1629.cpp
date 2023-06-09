#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
// a를 b번 곱함
ll go(ll a, ll b){
    if(b == 1) return a % c;

    ll ret = go(a, b/2); // a % c
    ret = (ret * ret) % c; // ((a % c) * (a % c)) % c
    if(b % 2) ret = (ret * a) % c; // a가 한번 남아있다면 곱하고 나눠준다.
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << go(a,b) << "\n";
}
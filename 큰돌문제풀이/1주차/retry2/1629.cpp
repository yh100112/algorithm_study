#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll go(ll a, ll b){
    if(b == 1) return a % c;

    ll ret = go(a, b / 2);
    ret = (ret * ret) % c; // ((a % c) * (a % c)) % c = (a * a) % c -> 이전 값 a%c를 사용
    if(b % 2 == 1) ret = (ret * a) % c; // 제일 처음으로 올라왔을 때 홀수일 수가 있음 이전에는 계속 짝수가 됨 ( 2로 나누므로 )
    return ret;
}

int main(){
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
}
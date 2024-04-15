#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[300004], ret = 1e18;
bool check(ll mid) {
    ll num = 0;
    for (int i = 0; i < m; i++) {
        num += a[i] / mid;
        if (a[i] % mid) num++;
    }
    return n >= num; // 보석을 나눈 수가 학생수보다 작거나 같을 때 true
    // 보석을 나눈 수가 학생수보다 크면 불가능
}

int main() {
    cin >> n >> m;
    ll lo = 1, hi = 0, mid; // hi : 가장 많은 같은 보석의 개수
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }

    // 이분탐색 꼴
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1; 
            // mid(질투심)가 최소일 때를 구하는 것이므로 찾은 mid보다 더 작은 것만 의미있으므로 hi를 mid - 1로 한것
        }
        else
            lo = mid + 1;
            // mid(질투심)로 나눴을 때 나눈 수가 학생수보다 큰 경우이므로 나눈 수를 학생수보다 적게 하기 위해 mid보다 큰 값으로 질투심을 설정
    }
    cout << ret << "\n";
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100004], lo, hi, ret, mx;

bool check(int mid) {
    ll cnt = 1, temp = mid;
    for (int i = 0; i < n; i++) {
        if (mid - a[i] < 0) {
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }

    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
       cin >> a[i];
       mx = max(mx, a[i]);
    }

    lo = mx, hi = 1000000004;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(check(mid)) {
            hi = mid - 1;
            ret = mid;
        }
        else
            lo = mid + 1;
    }
    cout << ret << "\n";
}
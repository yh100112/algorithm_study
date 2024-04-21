#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, z, lo, hi, ret = -1;

int main() {
    cin >> x >> y;
    z = y * 100 / x;
    lo = 1;
    hi = 1e9;    
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if ((y + mid) * 100 / (x + mid) > z) {
            hi = mid - 1;
            ret = mid;
        }
        else
            lo = mid + 1;
    }
    cout << ret << "\n";
}
// Z = Y * 100 / X;
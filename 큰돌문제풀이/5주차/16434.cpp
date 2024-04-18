
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, hatk, t[130000], a[130000], h[130000], lo = 1, hi, ret;

bool check(ll mid) {
  ll mxHp = mid;
  ll init_atk = hatk;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) {
      int cnt = h[i] % init_atk ? h[i] / init_atk + 1 : h[i] / init_atk;
      mid -= ((cnt - 1) * a[i]);
    } else {
      mid = min(mxHp, mid + h[i]);
      init_atk += a[i];
    }
    if (mid <= 0) return false;
  }

  return true;
}

int main() {
  cin >> n >> hatk;
  for (int i = 0; i < n; i++)
    cin >> t[i] >> a[i] >> h[i];
  hi = 1e18 + 4;
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
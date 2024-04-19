#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, atk, t[130000], a[130000], h[130000], ret, lo, hi;

// mid : maxhp
bool check(ll mid) {
  ll mxHp = mid;
  ll init_attack = atk;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) {
      ll cnt = h[i] % init_attack ? (h[i] / init_attack) + 1 : (h[i] / init_attack);
      if (mid - ((cnt - 1) * a[i]) <= 0)
        return false;
      mid -= ((cnt - 1) * a[i]);
    } else {
      mid = min(mxHp, mid + h[i]);
      init_attack += a[i];
    }
  }

  return true;
}

int main() {
  cin >> n >> atk;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> a[i] >> h[i];
  }
  lo = 1;
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
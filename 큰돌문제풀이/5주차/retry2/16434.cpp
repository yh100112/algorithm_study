#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, hatk, t[130000], a[130000], h[130000], lo, hi, ret;

bool check(ll mid) {
  ll mxHp = mid;
  ll init_attack = hatk;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) {
      ll cnt = h[i] % init_attack ? h[i] / init_attack + 1 : h[i] / init_attack; // 몬스터를 공격한 횟수
      if (a[i] * (cnt - 1) >= mid)
        return false;
      mid -= a[i] * (cnt - 1);
    }
    else {
      init_attack += a[i];
      mid = min(mid + h[i], mxHp);
    }
  }
  return true;
}

int main() {
  cin >> n >> hatk;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> a[i] >> h[i];
  }

  lo = 1;
  hi = 1e18 + 4;
  while(lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid - 1;
      ret = mid;
    }
    else
      lo = mid + 1;
  }
  cout << ret << "\n";
}
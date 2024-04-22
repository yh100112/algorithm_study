#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100004], lo, hi, mx, ret;

bool check(ll mid) {
  ll cnt = 1;
  ll temp = mid;
  for (int i = 0; i < n; i++) {
    if (mid - a[i] < 0) {
      cnt++;
      mid = temp;
    }
    mid -= a[i];
  }
  return cnt <= m;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }

  lo = mx;
  hi = 1e9 + 4;
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
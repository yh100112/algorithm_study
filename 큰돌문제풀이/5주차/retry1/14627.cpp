#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, lo, hi, mid, a[1000004], sum, ret;

bool check(ll mid) {
  int cnt = 0;
  for (int i = 0; i < s; i++)
    cnt += a[i] / mid;
  return cnt >= c;
}

int main() {
  cin >> s >> c;
  for (int i = 0; i < s; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + s);
  lo = 1;
  hi = 1e9;
  while(lo <= hi) {
    mid = (lo + hi) / 2;
    if(check(mid)) {
      ret = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << sum - ret * c << "\n";
}
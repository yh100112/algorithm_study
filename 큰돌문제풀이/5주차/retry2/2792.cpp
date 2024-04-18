#include<bits/stdc++.h>
using namespace std;
int n, m, a[300004], lo, hi, ret, mx;

bool check(int mid) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += (a[i] / mid);
    if (a[i] % mid)
      cnt++;
  }
  return cnt <= n;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }
  lo = 1;
  hi = mx;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      hi = mid - 1;
      ret = mid;
    }
    else
      lo = mid + 1;
  }
  cout << ret << "\n";
}
#include<bits/stdc++.h>
using namespace std;
int n, m, a[100004], mx, ret, lo, hi;

bool check(int mid) {
  if (mid < mx) return false;
  int cnt = 0;
  int temp = mid;
  for (int i = 0; i < n; i++) {
    if (mid - a[i] < 0) {
      mid = temp;
      cnt++;
    }
    mid -= a[i];
  }
  cnt++;
  return cnt <= m;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  lo = 1, hi = 1000000004;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid - 1;
      ret = mid;
    }
    else
      lo = mid + 1;
  }
  cout << ret << "\n";
}
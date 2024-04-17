#include<bits/stdc++.h>
using namespace std;
int t, n, m, a[20004], b[20004], ret;

int main() {
  cin >> t;
  while(t--) {
    ret = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i]; 
    sort(b, b + m);

    for (int i = 0; i < n; i++) {
      int lo = 0, hi = m - 1, mid;
      while(lo <= hi) {
        mid = (lo + hi) / 2;
        if (b[mid] < a[i]) {
          ret += (mid - lo + 1);
          lo = mid + 1;
        }
        else
          hi = mid - 1;
      }
    }
    cout << ret << "\n";
  }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S, C, a[1000004], lo, hi, mid, ret, sum;

bool check(ll mid) {
  int cnt = 0;
  for (int i = 0; i < S; i++) cnt += a[i] / mid;
  return cnt >= C;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> S >> C;
  for (int i = 0; i < S; i++) {
    cin >> a[i]; // 파의 길이
    sum += a[i];
  }
  
  lo = 1;
  hi = 1e9;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid + 1;
      ret = mid;
    }
    else
      hi = mid - 1;
  }
  cout << sum - ret * C << "\n";
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, z, lo, hi, ret = -1;

bool check(ll mid) {
  ll change_z = (y + mid) * 100 / (x + mid);
  return change_z > z;
}

int main() {
  cin >> x >> y; // x : 게임 횟수, y : 이긴 횟수, z : 승률(y / x * 100)
  z = y * 100 / x;
  lo = 1;
  hi = 1e9;
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
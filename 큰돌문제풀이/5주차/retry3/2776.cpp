#include<bits/stdc++.h>
using namespace std;
int t, n, m, num, lo, hi;

int check(int a[], int num) {
  lo = 0;
  hi = n - 1;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] > num)
      hi = mid - 1;
    else if (a[mid] == num)
      return 1;
    else
      lo = mid + 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
  cin >> t;
  while(t--) {
    cin >> n;
    int a[1000004];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> num;
      cout << check(a, num) << "\n";
    }
  }
}
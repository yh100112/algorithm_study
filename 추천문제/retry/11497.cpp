#include<bits/stdc++.h>
using namespace std;
int t, n;

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());

    int ret = 0;
    for (int i = 0; i < n - 2; i++)
      ret = max(ret, abs(v[i] - v[i + 2]));
    cout << ret << "\n";
  }
}
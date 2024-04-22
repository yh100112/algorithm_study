#include<bits/stdc++.h>
using namespace std;
int n, a[1004], cnt[1004], ret = INT_MIN;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  for (int i = 0; i < n; i++) {
    int maxValue = 0;
    int cur = a[i];
    for (int j = 0; j < i; j++)
      if (cur > a[j] && maxValue < cnt[j]) maxValue = cnt[j];
    cnt[i] = maxValue + 1;
    ret = max(cnt[i], ret);
  }
  cout << ret << "\n";
}
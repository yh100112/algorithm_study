#include<bits/stdc++.h>
using namespace std;
int n;
double psum[10004], a[10004], ret;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  double b = a[0];
  ret = b;
  for (int i = 1; i < n; i++) {
    if (b * a[i] < a[i])
      b = a[i];
    else
      b *= a[i];
    ret = max(ret, b);
  }
  printf("%.3f", ret);
}

/*
계산된 최댓값을 소수점 이하 넷째 자리에서 반올림하여 소수점 이하 셋째 자리까지 출력한다.
*/
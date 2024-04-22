#include<bits/stdc++.h>
using namespace std;
#define max_n 60000000004
#define MAX_M 10004
typedef long long ll;
// ret : 총시간, temp가 m : 여기서 부터 시작
ll n, m, a[MAX_M], lo, hi = max_n, ret, mid, temp;
bool check(ll mid) {
  temp = m; // 놀이기구 수만큼은 바로 태울 수 있으므로 m명은 태우고 시작
  for (int i = 0; i < m; i++) 
    temp += mid / a[i];
  return temp >= n; // 총 걸리는 시간이 mid일 때 n명이상 태울 수 있는지
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  if (n <= m) { cout << n; return 0; }
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      ret = mid; // 총 걸린 시간
      hi = mid - 1;
    } else
      lo = mid + 1;
  }

  // temp : 4분까지 태운 학생 수 -> 4분이 딱 됐을 때 바로 추가로 태울 수 있는데 그걸 뺀 순수하게 4분까지 태운 학생 수
  temp = m;
  for (int i = 0; i < m; i++)
    temp += ((ret - 1) / a[i]);
  
  // 4분부터 시작해서 다시 순차적으로 놀이기구 테움 -> 즉, 여기서는 놀이기구에 아무도 타있지 않은 초기 상태임
  for (int i = 0; i < m; i++) {
    if (ret % a[i] == 0) temp++; // % 연산의 결과가 0이 아날 경우 == 놀이기구에 이미 학생이 탑승되어 있음
    if (temp == n) {
      cout << i + 1 << "\n";
      return 0;
    }
  }
  return 0;
}

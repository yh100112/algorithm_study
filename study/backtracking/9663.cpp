#include<iostream>
using namespace std;
bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt = 0;
int n;
void func(int cur) {
  if (cur == n) {
    cnt++;
    return;
  }

  // i는 세로줄(y) 인덱스, cur는 아래로 한개씩 내려가므로 가로줄(x) 인덱스
  for (int i = 0; i < n; i++) {
    if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1])
      continue;
    isused1[i] = 1;
    isused2[cur+i] = 1;
    isused3[cur-i+n-1] = 1;
    func(cur+1);
    isused1[i] = 0;
    isused2[cur+i] = 0;
    isused3[cur-i+n-1] = 0;
  }
}

int main(){
  cin >> n;
  func(0);
  cout << cnt;
}
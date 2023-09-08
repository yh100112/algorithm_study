#include<iostream>
#include<deque>

using namespace std;

int main() {
  int N, L; // n개의 수 
  cin >> N >> L;
  
  deque<int> dq;
  int a, i, j;
  int min = 1;
  for (i = 0; i < N; ++i) {
    cin >> a;
    dq.push_back(a);
  }
  
  for (i = 0; i < N; ++i) {
    if (i + 1 <= L) {
      int range;
      if (i+1-L+1 < 1) {
        range = i + 1;
      }
      min = dq[0];
      for (j = 0; j < range; ++ j) {
        if (min > dq[j]) {
          min = dq[j];
        }
      }
      cout << min << " ";
    }
    else {
      dq.pop_front();
      min = dq[0];
      for (j = 0; j < L; ++ j) {
        if (min > dq[j]) {
          min = dq[j];
        }
      }
      cout << min;
      if (i != N)
        cout << " ";
      else
        cout << endl;
    }
  }
}
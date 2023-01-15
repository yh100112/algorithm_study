#include<iostream>
#include<deque>

using namespace std;

int main() {
  int n, m, i;
  int min = 0;
  cin >> n >> m; // 큐의 크기, 뽑으려 하는 수의 개수

  deque<int> dq;
  for (int i = 0; i < n; ++i)
    dq.push_back(i + 1);

  int index;
  while(m--) {
    int num;
    cin >> num;

    for (i = 0; i < dq.size(); ++i) {
      if (dq[i] == num) {
        index = i;
        break;
      }
    }

    // 절반 이하면 2번
    if (index <= dq.size() / 2) {
      while (true) {
        if (dq.front() == num) {
          dq.pop_front();
          break;
        }

        dq.push_back(dq.front());
        dq.pop_front();
        ++min;
      }
    }
    // 절반 초과면 3번
    else {
      while (true) {
        if (dq.front() == num) {
          dq.pop_front();
          break;
        }

        dq.push_front(dq.back());
        dq.pop_back();
        ++min;
      }
    }
  }
  cout << min << endl;
}
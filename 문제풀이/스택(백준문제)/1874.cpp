#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n, i;
  cin >> n;

  int cnt = 1;
  stack<int> s;
  string ans;
  while(n--) {
    int c;
    cin >> c;

    while (cnt <= c) {
      s.push(cnt++);
      ans += "+\n";
    }

    if (s.top() != c) {
      cout << "NO" << "\n";
      return 0;
    }

    s.pop();
    ans += "-\n";
  }
  cout << ans;
}
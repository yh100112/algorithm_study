#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n, i;
  cin >> n;

  stack<int> s;
  int cnt = 1;
  string ans;

  while (n--) {
    int num;
    cin >> num;

    while (cnt <= num) {
      s.push(cnt++);
      ans += "+\n";
    }

    if (s.top() != num) {
      cout << "NO" << endl;
      return 0;
    }

    s.pop();
    ans += "-\n";
  }
  cout << ans;
}
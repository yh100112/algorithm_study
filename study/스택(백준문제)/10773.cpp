#include<iostream>
#include<stack>

using namespace std;

int main() {
  int c;
  string ans;
  cin >> c;

  stack<int> s;
  while(c--) {
    cin >> ans;
    if (ans == "0") {
      s.pop();
    }
    else {
      s.push(stoi(ans));
    }
  }


  int size = s.size();
  int sum = 0;

  for (int i = 0; i < size; ++i) {
    sum += s.top();
    s.pop();
  }
  cout << sum << "\n";
}
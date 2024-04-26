#include<bits/stdc++.h>
using namespace std;
int n, temp[1000004], len, num;
const int INF = 1e9 + 4;
pair<int,int> ans[1000004];
stack<int> st;

int main() {
  cin >> n;
  fill(temp, temp + 1000004, INF);
  for (int i = 0; i < n; i++) {
    cin >> num;
    auto lowerPos = lower_bound(temp, temp + len, num);
    int pos_ = lowerPos - temp;
    if (*lowerPos == INF) len++;
    *lowerPos = num;
    ans[i].first = pos_;
    ans[i].second = num;
  }
  cout << len << "\n";
  for (int i = n - 1; i >= 0; i--) {
    if(ans[i].first == len - 1) {
      st.push(ans[i].second);
      len--;
    }
  }

  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
#include<iostream>
#include<queue>

using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& t, const pair<int, int>& u) {
    return t.first > u.first;
  }
};

int main() {
  int N, L;
  cin >> N >> L;

  int val;
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

  for(int i = 0; i < N; ++i) {
    cin >> val;
    pq.push(make_pair(val, i));
    int start = i - L + 1;
    while (start >= 0 && pq.top().second < start)
      pq.pop();
    cout << pq.top().first << endl;
  }

  return 0;
}
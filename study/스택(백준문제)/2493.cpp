#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> tower;

int main() {
  cin >> N;

  tower.push({100000001, 0});
  for (int i = 1; i <= N; ++i) {
    int height;
    cin >> height;

    while (tower.top().first < height)
      tower.pop();

    cout << tower.top().second << " ";
    tower.push({height, i});
  }
}
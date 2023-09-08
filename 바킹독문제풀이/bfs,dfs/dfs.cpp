#include<iostream>
#include<vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x)
{
  if (c[x]) return; // 현재 그 노드가 방문한 노드라면 바로 함수 종료
  c[x] = true;
  cout << x << ' ';
  // 현재 노드랑 인접한 노드 끝까지 방문함
  for (int i = 0; i < a[x].size(); ++i) {
    int y = a[x][i];
    dfs(y);
  }
}

int main() {
  a[1].push_back(2);
  a[2].push_back(1);

  a[1].push_back(3);
  a[3].push_back(1);

  a[2].push_back(4);
  a[4].push_back(2);

  a[2].push_back(5);
  a[5].push_back(2);

  a[3].push_back(6);
  a[6].push_back(3);

  a[3].push_back(7);
  a[7].push_back(3);
  
  a[4].push_back(5);
  a[5].push_back(4);
  
  a[6].push_back(7);
  a[7].push_back(6);

  dfs(1);
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start) {
  queue<int> q;
  q.push(start); // queue에 현재 노드 값을 저장
  c[start] = true; // 방문처리
  
  while (!q.empty()) {
    int x = q.front(); // 큐에서 제일 앞에 있는 값을 저장
    q.pop(); // 큐에서 제일 앞에 있는 값을 삭제
    printf("%d", x);
    
    // 현재 큐에서 꺼낸 노드의 인접 노드들을 확인
    for (int i = 0; i < a[x].size(); ++i) {
      int y = a[x][i]; 
      if (!c[y]) { // 방문하지 않은 노드라면 큐에 넣고 방문처리
        q.push(y);
        c[y] = true;
      }
    }
  }
}
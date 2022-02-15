#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int number = 7; // 노드의 갯수
int c[7]; // 방문처리를 위한 배열 생성
vector<int> a[8];

void bfs(int start){
  queue<int> q;
  q.push(start);
  c[start] = true;
  while(!q.empty()){
    int x = q.front(); // 큐에서 제일 앞에 값을 저장
    q.pop(); // 큐에서 제일 앞에 값을 삭제
    printf("%d ",x);
    for(int i = 0; i < a[x].size(); i++){
      int y = a[x][i];
      if(!c[y]){
        q.push(y);
        c[y] = true;
      }
    }
  }
}

int main(){
  a[1].push_back(2);
  a[1].push_back(3);
  
}



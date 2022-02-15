#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int number = 7; // 노드의 갯수
int c[7]; // 방문처리를 위한 배열 생성
vector<int> a[8]; // 이차원 배열

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
      if(!c[y]){ // 방문하지 않았으면
        q.push(y);
        c[y] = true;
      }
    }
  }
}

int main(){
  //1과 2를 연결
  a[1].push_back(2);
  a[2].push_back(1);
  
  //1과 3을 연결
  a[1].push_back(3);
  a[3].push_back(1);

  //2와 3을 연결
  a[2].push_back(3);
  a[3].push_back(2);

  //2와 4를 연결
  a[2].push_back(4);
  a[4].push_back(2);
  
  //2와 5를 연결
  a[2].push_back(5);
  a[5].push_back(2);

  //3과 6을 연결
  a[3].push_back(6);
  a[6].push_back(3);

  //3과 7을 연결
  a[3].push_back(7);
  a[7].push_back(3);

  //4와 5를 연결
  a[4].push_back(5);
  a[5].push_back(4);

  //6과 7을 연결
  a[6].push_back(7);
  a[7].push_back(6);

  //BFS를 수행
  bfs(1);

  
}



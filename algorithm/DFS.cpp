/*
기본적으로 재귀 호출 자체가 컴퓨터의 내부적인 구조인 스택 구조에 차곡차곡
쌓이는 형태기 때문에 간단히 재귀함수로 구현을 하는 것 만으로도 사실 스택에 담고
빼는 것과 같은 효과가 나온다. 그렇기 때문에 스택을 따로 쓰지 않고 재귀만 구현해서 dfs를 구현할 수 있다.
*/

#include<iostream>
#include<vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x){
  if(c[x]) return; // 현재 그 노드가 방문한 노드라면 바로 함수 종료
  c[x] = true;
  cout << x << ' ';
  for(int i = 0; i < a[x].size(); i++){
    int y = a[x][i];
    dfs(y);
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

  dfs(1);
}
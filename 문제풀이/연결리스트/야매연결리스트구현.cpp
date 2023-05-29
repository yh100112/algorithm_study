#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

// addr은 배열상에서 현재 값이 있는 끝이 몇번지인지를 의미
// 만약 원소 13이 2번지이고 13뒤에 20을 추가하고 싶다면 insert(2, 20)을 호출해야 함
// 13을 지우고 싶다면 erase(2)를 호출해야 함 2가 의미하는 것이 연결 리스트 상에서
// 2번째 원소라는 것이 아니라 해당 원소의 주소가 2번지라는 점을 헷갈리면 안됨
void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = 
}

void erase(int addr){

}

void traverse(){
  int cur = nxt[0]; // cur에 각각의 값이 들어있는 주소값이 들어감
  while(cur != -1){ // 쭉 출력하다가 cur에 -1이 담기면 끝에 도달해 while문 탈출
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  // erase_test();
}
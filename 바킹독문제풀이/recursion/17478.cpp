#include<iostream>
#include<string>
using namespace std;
string line = "";

void func(int n) {
  if(n == 0) {
    cout << line + "\"재귀함수가 뭔가요?\"\n";
    cout << line + "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    cout << line + "라고 답변하였지.\n";
    return;
  }
  cout << line + "\"재귀함수가 뭔가요?\"\n";
  cout << line + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
  cout << line + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
  cout << line + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
  line += "____";
  func(n-1);
  line.erase(0,4);
  cout << line + "라고 답변하였지.\n";
}

int main(){
  int n;
  cin >> n;
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
  func(n);
}

/*
문제를 풀고 알게 된 점
- 재귀함수는 중간에 자신을 호출하는 함수가 있으면 그 전까지것들을 다 동작하고 
  base condition을 리턴한 뒤 그 뒤에 있는 것들을 역순서로 동작시킨다.
*/
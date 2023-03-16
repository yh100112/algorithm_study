#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
void sec(int N, vector<pair<int,int>>& v, vector<int>& time){
  for(int i=0; i<N; i++)
    if (v[i].first != 0)
      time.push_back(v[i].first);
}

vector<int> solution(int N, vector<int> coffee_times) {
  vector<int> answer;
  queue<int> Q; // coffee times
  vector<pair<int,int>> machine; // 초, 번호
  for(int i=0; i < coffee_times.size(); ++i)
    Q.push(coffee_times[i]);
  int num = 1;
  for(int i=0; i<N; i++) {
    machine.push_back({Q.front(),num++}); 
    Q.pop();
  }
  while(true) {
    bool end = true;
    for(int i=0; i<N; i++)
      if(machine[i].first != 0)
        end = false;
    if(end)
      break;

    vector<int> zero_idx;
    for(int i=0; i<N; i++)
      if(machine[i].first == 0)
        zero_idx.push_back(i);

    vector<int> time; // 초
    sec(N,machine,time);
    int min = *min_element(time.begin(), time.end());
    for(int i=0; i<N; i++)
      if (machine[i].first != 0)
        machine[i].first -= min; // 초 차감
    for(int i=0; i<N; i++){
      if (find(zero_idx.begin(), zero_idx.end(), i) == zero_idx.end()) { // 시작할 때 초가 0인 머신이 아니면
        if(machine[i].first == 0){
          answer.push_back(machine[i].second);
          if (!Q.empty()) {
            machine[i].first = Q.front();
            Q.pop();
          }
          machine[i].second = num++; // 새로운 번호 대입
        }
      }
    }
  }
  return answer;
}

int main(){
  vector<int> coffee = {4,2,2,5,3};
  vector<int> ans = solution(3,coffee);
  for(auto& v: ans)
    cout << v << " ";
  cout << endl;
}
// gabia coding test 3번 ( 프로그래머스 ide에서는 에러를 못찾고 못품 -> vscode에서는 품 ㅡㅡ)
// 프로그래머스 ide 익숙해지도록 연습
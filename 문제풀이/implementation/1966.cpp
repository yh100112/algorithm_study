#include<bits/stdc++.h>
using namespace std;
int n, a, k, num, ret;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num >> k; // k : 몇번째
    queue<pair<int,int>> q;
    vector<int> ss;
    for(int j = 0; j < num; j++){
      cin >> a;
      q.push({a,j});
      ss.push_back(a);
    }
    int max = *max_element(ss.begin(), ss.end());
    int cnt = 0;
    while(!q.empty()){
      for(int j = 0; j < q.size(); j++){
        int prio = q.front().first;
        int turn = q.front().second;
        if(prio == max){
          if(turn == k) { // 찾는 순번
            cout << cnt+1 << "\n";
            while(!q.empty()) q.pop();
            break;
          } // 찾는 순번 x
          else {
            q.pop();
            ss.erase(remove(ss.begin(), ss.end(), prio), ss.end());
            max = *max_element(ss.begin(),ss.end());
            cnt++;
          }
        }
        else {
          q.pop();
          q.push({prio, turn});
        }
      }
    }
  }
}
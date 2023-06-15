#include<iostream>
#include<vector>
using namespace std;
int n, k;
vector<int> ret;
int ck[5004];

int main(){
  cin >> n >> k;
  int st = -1;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    cnt = 0;
    while(cnt < k) {
      st++;
      if(st >= n) {
        st = 0;
      }
      if(ck[st]) continue;
      cnt++;
    }
    ret.push_back(st+1);
    ck[st] = 1;
  }

  cout << "<";
  for(int i = 0; i < ret.size(); i++){
    cout << ret[i];
    if(i == ret.size() - 1)
      cout << ">\n";
    else
      cout << ", ";
  }
}
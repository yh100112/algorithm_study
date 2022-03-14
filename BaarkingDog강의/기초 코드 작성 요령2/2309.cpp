#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v(9);
  int sum = 0;
  int fake = 0;
  int check = 0;
  for(int i = 0; i < 9; i++){
    cin >> v[i];
    sum += v[i];
  }
  
  fake = sum - 100;
  for(int i = 0; i < 9; i++){
    for(int j = i+1; j < 9; j++){
      if(v[i] + v[j] == fake){
        v.erase(v.begin() + i);
        v.erase(v.begin() + j - 1);
        check = 1;
        break;
      }
    }
    if(check == 1) break;
  }

  sort(v.begin(), v.begin()+7);
  for(int i = 0; i < 7; i++){
    cout << v[i] << "\n";
  }
}


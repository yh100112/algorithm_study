#include<bits/stdc++.h>
using namespace std;

int input[101];
int pplus[101];
int mminus[101];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, v;
  cin >> N;
  for(int i=0; i<N; ++i){
    cin >> input[i];
    if(input[i] >= 0){
      pplus[input[i]]++;
    }else{
      mminus[abs(input[i])]++;
    }
  }
  cin >> v;

  if(v >= 0){
    cout << pplus[v];
  }else{
    cout << mminus[abs(v)];
  }
}
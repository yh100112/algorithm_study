#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, k;
  int s,y;
  cin >> N >> k;

  int a[2][7] = {0,};
  for(int i=0; i<N; i++){
    cin >> s >> y;
    a[s][y]++;
  }

  int room = 0;
  for(int i=1; i<=6; i++){
    if(a[0][i] != 0){
      if(a[0][i] % k == 0){
        room = room + (a[0][i] / k);
      }else{
        room = room + (a[0][i] / k) + 1;
      }
    }

    if(a[1][i] != 0){
      if(a[1][i] % k == 0){
        room = room + (a[1][i] / k);
      }else{
        room = room + (a[1][i] / k) + 1;
      }
    }
  }

  cout << room;
}

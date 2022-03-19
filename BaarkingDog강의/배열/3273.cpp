#include<bits/stdc++.h>
using namespace std;

int arr[2000001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,x,a;
  int cnt = 0;

  cin >> n;
  int num[n] = {0,};

  for(int i = 0; i < n; i++){
    cin >> num[i];
  }
  cin >> x;
  
  for(int i = 0; i < n; i++){
    if(x - num[i] > 0 && arr[x - num[i]]) cnt++;
    arr[num[i]] = 1;
  }

  cout << cnt;
}

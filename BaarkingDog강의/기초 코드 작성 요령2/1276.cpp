#include<bits/stdc++.h>
using namespace std;

int main(void){
  int cnt,a;
  int sum_y = 0;
  int sum_m = 0;
  cin >> cnt;
  
  int arr[cnt];  
  for(int i = 0; i < cnt; i++){
    cin >> arr[i];
  }

  int cost;
  for(int i = 0; i < cnt; i++){
    cost = (arr[i] / 30) * 10 + 10;
    sum_y += cost;
  }

  for(int i = 0; i < cnt; i++){
    cost = (arr[i] / 60) * 15 + 15;
    sum_m += cost;
  }

  if(sum_y > sum_m){
    cout << "M " << sum_m; 
  }else if(sum_y < sum_m){
    cout << "Y " << sum_y;
  }else{
    cout << "Y M " << sum_y;
  }
}

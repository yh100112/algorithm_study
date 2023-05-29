#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a,b,c;
  string res;
  cin >> a >> b >> c;
  res = to_string(a * b * c);

  int arr[10] = {0,};

  for(int i = 0; i < res.length(); i++){
    arr[res[i] - '0']++;
  }

  for(auto c : arr)
    cout << c << "\n";

}
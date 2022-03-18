#include<bits/stdc++.h>
using namespace std;

int arr[123] = {0,};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  for(int i = 0; i < s.length(); i++){
    arr[s[i]]++;
  }

  for(int i = 97; i <= 122; i++){
    cout << arr[i] << " ";
  }

  

}
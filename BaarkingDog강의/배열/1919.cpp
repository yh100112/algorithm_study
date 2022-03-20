#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr1[26]={};
  int arr2[26]={};
  string a,b;
  cin >> a >> b;

  for(int i=0; i<a.length(); i++)
    arr1[a[i] - 'a']++;
  for(int i=0; i<b.length(); i++)
    arr2[b[i] - 'a']++;

  int ans = 0;
  for(int i=0; i<26; i++){
    if(arr1[i] != arr2[i]){
      ans += abs(arr1[i] - arr2[i]);
    }
  }

  cout << ans;

}
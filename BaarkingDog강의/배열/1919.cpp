#include<bits/stdc++.h>
using namespace std;

// 내가 쓴 코드
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int arr1[26]={};
//   int arr2[26]={};
//   string a,b;
//   cin >> a >> b;

//   for(int i=0; i<a.length(); i++)
//     arr1[a[i] - 'a']++;
//   for(int i=0; i<b.length(); i++)
//     arr2[b[i] - 'a']++;

//   int ans = 0;
//   for(int i=0; i<26; i++){
//     if(arr1[i] != arr2[i]){
//       ans += abs(arr1[i] - arr2[i]);
//     }
//   }

//   cout << ans;
// }

//바킹독 코드
int arr[2][26], res;
string s1, s2;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2;
  for(char c : s1)
    arr[0][c - 'a']++;
  
  for(char c : s2)
    arr[1][c - 'a']++;
  
  for(int i=0; i<26; i++)
    res += abs(arr[0][i]-arr[1][i]);
  
  cout << res;
}
#include<bits/stdc++.h>
using namespace std;


//내가 짠 코드
/*
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
*/

//바킹독 코드
int freq[26];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  for(auto c : s)
    freq[c - 'a']++;
  for(int i = 0; i < 26; i++)
    cout << freq[i] << " ";
}
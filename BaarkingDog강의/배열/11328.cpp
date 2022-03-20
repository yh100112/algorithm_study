#include<bits/stdc++.h>
using namespace std;

// 내가 짠 코드
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int N;
//   int check = 0;
//   cin >> N;
  
//   int arr1[26] = {0,};
//   int arr2[26] = {0,};
//   string a,b;
//   for(int i=0; i<N; i++){
//     cin >> a >> b;
//     for(int i=0; i<a.length(); i++)
//       arr1[a[i] - 'a']++;
//     for(int i=0; i<b.length(); i++)
//       arr2[b[i] - 'a']++;
//     for(int i=0; i<sizeof(arr1)/sizeof(arr1[0]); i++){
//       if(arr1[i] != arr2[i]){
//         cout << "Impossible" << "\n";
//         break;
//       }
//       if(i == 25) cout << "Possible" << "\n";
//     }
//     fill(arr1,arr1+26,0);
//     fill(arr2,arr2+26,0);
//   }
// }

//바킹독 코드
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  while(N--){
    int a[26] = {};
    string s1,s2;
    cin >> s1 >> s2;

    for(auto c : s1) a[c - 'a']++;
    for(auto c : s2) a[c - 'a']--;

    bool isPossible = true;
    for(int i : a){
      if(i != 0) isPossible = false;
    }
    
    if(isPossible) cout << "Possible\n";
    else cout << "Impossible\n";
  }
}
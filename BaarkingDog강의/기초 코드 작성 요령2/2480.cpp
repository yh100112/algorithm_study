// 내가 짠 코드
// #include<iostream>
// using namespace std;

// int main(){
//   int arr[3];
//   cin >> arr[0] >> arr[1] >> arr[2];

//   if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[0]){
//     cout << 10000 + arr[0] * 1000 << "\n";
//   }
//   else if((arr[0] == arr[1] && arr[1] != arr[2]) || (arr[1] == arr[2] && arr[2] != arr[0]) || 
//   (arr[2] == arr[0] && arr[0] != arr[1]))
//   {
//     if(arr[0] == arr[1]){
//       cout << 1000 + arr[0] * 100 << "\n";
//     }else if(arr[1] == arr[2]){
//       cout << 1000 + arr[1] * 100 << "\n";
//     }else{
//       cout << 1000 + arr[2] * 100 << "\n";
//     }
//   }else{
//     int max = 0;
//     for(int i = 0; i < 3; i++){
//       if(max < arr[i]) max = arr[i];
//     }
//     cout << max * 100 << "\n";
//   }
// }


//다른 사람이 짠 코드
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int a,b,c;
//   cin >> a >> b >> c;
//   if(a == b && b == c) cout << 10000 + a * 1000;
//   else if(a == b || a == c) cout << 1000 + a * 100;
//   else if(b == c) cout << 1000 + b * 100;
//   else cout << max({a,b,c}) * 100;
// }

//더 잘 짠 코드
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a,a+3);
  if(a[0] == a[2]) cout << 10000 + a[0] * 1000; // 세 수가 동일
  else if(a[0] == a[1] || a[1] == a[2]) cout << 1000 + a[1] * 100; // 두 수가 동일
  else cout << a[2] * 100;
}
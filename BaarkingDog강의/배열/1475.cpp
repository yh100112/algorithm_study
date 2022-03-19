#include<bits/stdc++.h>
using namespace std;


// 내가 짠 코드
// int arr[10];

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   string N;
//   cin >> N;

//   for(int i = 0; i < N.length(); i++){
//     arr[N[i] - '0']++;
//   }

//   int max = 0;
//   int max_num = -1;
//   for(int i = 0; i < 10; i++){
//     if(max < arr[i]){
//       max = arr[i];
//       max_num = i;
//     } 
//   }

//   if(max_num == 9 || max_num == 6){
//     if(max_num == 9){
//       max += arr[6];  
//     }else{
//       max += arr[9];
//     }

//     if(max % 2 == 0){
//       max = max / 2;
//     }else{
//       max = max / 2 + 1;
//     }
//   }

//   for(int i = 0; i < 10; i++){
//     if(i != 6 && i != 9){
//       if(max <= arr[i]){
//         max = arr[i];
//       }
//     }
//   }

//   cout << max;
// }


//바킹독 코드
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // ans = 1로 둠으로써 N = 0일 때에 대한 예외처리가 자연스럽게 가능해짐
  int N, a[10] = {}, ans = 1;
  cin >> N;

  // 자리수 추출
  while(N){
    a[N % 10]++;
    N /= 10;
  }

  for(int i = 0; i < 10; i++){
    if(i == 6 || i == 9) continue;
    ans = max(ans, a[i]);
  }

  //(a[6] + a[9])/2 를 올림한 값이  6,9에 대한 필요한 세트의 수이므로 (a[6] + a[9] + 1)/2 를 계산
  ans = max(ans, (a[6] + a[9] + 1)/2);
  cout << ans;
}
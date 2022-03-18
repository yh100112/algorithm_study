#include<iostream>
using namespace std;

// O(N^2)
// int func2(int arr[], int n){
//   for(int i = 0; i < n; i++){
//     for(int j = i+1; j < n; j++){
//       if(arr[i] + arr[j] == 100) return 1;
//     }
//   }
//   return 0;
// }


// 시간복잡도 O(N)
int a[101];

int func2(int arr[], int n){
  for(int i = 0; i < n; i++){
    if(a[100 - arr[i]] == 1){
      return 1;
    } 
    a[arr[i]] = 1;
  }
  return 0;
}

int main(){
  int arr[] = {50,42,54};
  cout << func2(arr,3) << endl;
} 

/*
문제)
주어진 길이 N의 int배열 arr에 합이 100인 사로 다른 위치의 두 원소가 존재하면
1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int n)을 작성하라.

이 코드는 O(N^2)의 시간 복잡도를 가진다.
(n-1) + (n-2) + ... + 3 + 2 + 1 = (N^2 - N) / 2 => O(N^2)

하지만 실제로 이 문제는 O(n)의 시간복잡도를 가지도록 구현 가능하다!
*/
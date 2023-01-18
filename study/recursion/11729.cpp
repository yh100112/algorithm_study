#include<iostream>
using namespace std;

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 함수
void func(int a, int b, int n){
  if(n == 1){
    cout << a << ' ' << b << '\n';
    return;
  }
  func(a, 6-a-b, n-1); // n-1개를 a -> 6-a-b로 이동
  cout << a << ' ' << b << '\n'; // n번 돌을 a -> b로 이동
  func(6-a-b, b, n-1); // n-1개를 6-a-b -> b로 이동
}
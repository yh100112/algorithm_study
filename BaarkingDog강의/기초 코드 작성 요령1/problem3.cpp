#include<iostream>
using namespace std;

int func3(int n){
  for(int i = 1; i * i <= n; i++){
    if(i * i == n) return 1;
  }
  return 0;
}

/*
문제)
n이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을
작성하라. N은 10억 이하의 자연수이다.

func3(9) = 1
func3(693953651) = 0
func(756580036) = 1

이 경우 시간복잡도는 i가 1,2,... 루트n까지 가게 되니
시간복잡도는 O(루트n)이 된다.
*/
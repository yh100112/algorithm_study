#include<stdio.h>
#include<iostream>
using namespace std;

template<typename T>
T cast(int s){
  return (T)s;
}

template<typename T>
void func(void){
  T v;

  cin >> v;
  cout << v;
}

int main(){
  int i=cast<int>(1234);//      cast(1234)라고만 쓰면 어떤 함수를 원하는지 모호하므로 <>안에 타입을 명시해준다.
  double d = cast<double>(5678);
  

  printf("i = %d, d=%f\n",i,d);
  func<int>(); // 지역변수 v의 타입을 명시적으로 전달
}
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class test{
private:
  int a;
public:
  test(int val = 0):a(val){}
  void get(){
    printf("%d\n",a);
  }
};

int main(){
  test aa = test(); // 명시적 호출
  aa.get(); // 0

  test bb = test(10); // 명시적 호출
  bb.get(); // 10

  test cc(100); // 암시적 호출
  cc.get(); // 100

  test ccc;
  ccc.get();

  test(10); // 임시객체
  test(10).get(); // 임시객체이므로 실행도중 잠깐만 사용되는 객체임
}
#include<stdio.h>

void hello(){
  printf("hello, world!\n");
}

void bonjour(){
  printf("bonjour le monde!\n");
}

int main(){
  void(*fp)(); // 반환값과 매개변수가 없는 함수 포인터 fp 선언
  fp = hello; // hello함수의 메모리 주소를 함수 포인터 fp에 저장
  fp(); // hello, world! : 함수 포인터로 hello() 호출

  fp = bonjour;
  fp(); // 함수 포인터로 bonjour 함수 호출

  return 0;
}
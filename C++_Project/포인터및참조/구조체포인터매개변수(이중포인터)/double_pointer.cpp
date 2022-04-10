/*
포인터의 메모리 주소를 저장하는 이중포인터
*/

#include<stdio.h>

int main(){
  int* numPtr1;
  int** numPtr2;
  int num1 = 10;

  numPtr1 = &num1;
  numPtr2 = &numPtr1;

  printf("%d\n",**numPtr2);

  return 0;
}
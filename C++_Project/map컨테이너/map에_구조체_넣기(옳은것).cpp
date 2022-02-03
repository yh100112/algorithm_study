#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
using namespace std;

struct File{
  int a = 2;
  int b = 3;
  char* read_curr_ptr = (char*)&a;
};

int main(){
  map<int,struct File> m;
  m[1]; // value로 구조체 File이 알아서 생성됨.

  printf("%p %p\n",&m[1].a,m[1].read_curr_ptr); // 두개의 주소가 같음
  

  return 0;
}
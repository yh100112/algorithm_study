#include<iostream>
#include<malloc.h>
using namespace std;

int main(){
  int *point = new int[5]; // 배열 형태 메모리 동적할당

  for(int i=0; i<5; i++){
    point[i] = i;
  }

  cout << sizeof(point) << endl; // 8바이트
  cout << sizeof(*point) <<endl; // 4바이트
  delete[] point; // 배열 형태 메모리 할당해제

  return 0;
}
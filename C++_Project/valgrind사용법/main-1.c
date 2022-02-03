#include<stdio.h>
#include<stdlib.h>

void f(){
  int* x = malloc(10*sizeof(int));
}

//problem1 : memory leak -- x not freed
//메모리를 할당하고 해제하는 코드가 없다. 이런 건 컴파일러에서 찾을 수 없는데 valgrind에서 어떻게 찾는지확인해보자.
/*
사용법
1.gcc -o main-1 main-1.c
2. valgrind ./main-1
*/
int main(){
  f();
  return 0;
}
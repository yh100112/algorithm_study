#include<stdlib.h>
#include<stdio.h>

void f(void) {
  int* x = malloc(10 * sizeof(int));
  x[10] = 0;        // problem 2: 할당되지 않은 메모리 주소에 값을 작성할 때
  free(x);
}

int main(void) {
  f();

  return 0;
}
#include<stdio.h>

int& RefFunc(int val){
  val++;
  return val;
}


int main(){
  int n1 = 10;
  int& ref1 = RefFunc(n1);  // 함수의 반환값은 지역변수라서 함수가 끝나는 순간 소멸된다. 결국 ref1은 소멸된 지역변수를 가리키게 되며, 이 경우
                            // 컴파일러 에러가 나지 않고 경고만 띄우고 종료된다.

  n1++;
  ref1++;
  printf("n1 : %d / ref1 : %d \n",n1,ref1);
}
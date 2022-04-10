#include<stdio.h>

int& RefFunc(int& val){
  val++;
  return val;
}


int main(){
  int n1 = 10;
  int& ref1 = RefFunc(n1); //ref1은 n1 그 자체이다. 이해 안가면 참조에의한전달(map에서).cpp 파일 보자

  n1++;
  ref1++;
  printf("n1 : %d / ref1 : %d \n",n1,ref1); // n1과 ref1은 둘다 n1 그 자체이므로 같이 똑같이 올라감.
}
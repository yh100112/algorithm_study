#include<stdio.h>

void swap(int* num1, int* num2){
  int temp;

  temp = *num1;
  *num1 = *num2; //역참조!!!
  *num2 = temp;
}

int main(){
  int num1 = 20;
  int num2 = 30;

  printf("num1:%d | num2:%d\n",num1,num2);
  swap(&num1,&num2);
  printf("num1:%d | num2:%d\n",num1,num2);

}
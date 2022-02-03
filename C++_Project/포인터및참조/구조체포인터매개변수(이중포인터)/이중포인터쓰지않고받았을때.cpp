#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<string.h>

struct Person{
  int age;
  char name[20];
};

void test(struct Person* p1){ 
  printf("&p1 : %p\n",&p1); 
  printf("p1 : %p\n",p1); // p1 : null

  p1 = (struct Person*)malloc(sizeof(struct Person)); //그저 지역변수로 선언된 struct Person* p1을 동적할당 한 것이다. 

  printf("동적할당 후 p1 : %p | &p1 : %p\n",p1,&p1); // p1 : 0x22b2c0s 

  p1->age = 20;
  strcpy(p1->name,"hello");
}

int main(){
  struct Person *p1;
  printf("메인의 p1 : %p | &p1 : %p\n",p1,&p1); // p1 : null

  test(p1);

  printf("test 호출 후 메인의 p1 : %p\n",p1); // p1 : null

  free(p1);

}
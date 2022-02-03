#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<string.h>

struct Person{
  int age;
  char name[20];
};

void test(struct Person** p1){ 

  printf("매개변수 p1 : %p\n",p1); 
  printf("매개변수 p1을 역참조한 것 : %p\n",*p1); 

  *p1 = (struct Person*)malloc(sizeof(struct Person)); 

  printf("동적할당 후 매개변수 p1을 역참조한 것 : %p\n",*p1); 
  (*p1)->age = 20;
  strcpy((*p1)->name,"hello");
}

int main(){
  struct Person *p1;

  printf("메인의 p1 : %p | &p1 : %p\n",p1,&p1); 

  test(&p1);

  printf("test 호출 후 메인의 p1 : %p\n",p1); 

  printf("%d\n",p1->age);
  printf("%s\n",p1->name);

  free(p1);

}
#include<stdio.h>
#include<stdlib.h>


struct Student{
  char* name;
  char* major;
  int stu_num;
  Student(char* n,int sn, char* m):name(n),stu_num(sn),major(m){};
  Student(){
    name = "홍길동";
    stu_num = 123456;
    major = "학과";
  }

  ~Student(){
    printf("소멸자실행\n");
  }
};

int main(int argc, char* argv[]){
  struct Student stu1;
  struct Student stu2("김철수",1111,"학과2");

  printf("이름 : %s 학번 : %d 전공 : %s\n",stu1.name,stu1.stu_num,stu1.major);
  printf("----------------------------------\n");
  printf("이름 : %s 학번 : %d 전공 : %s\n",stu2.name,stu2.stu_num,stu2.major);
  
}
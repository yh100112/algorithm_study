#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Student
{
private:
  char* name;
  int age;
public:
  Student(char* name, int age):age(age)
  {
    this->name = new char[10];
    strcpy(this->name,name); // name을 this->name에 복사
  }
  void ShowInfo(){
    cout << "이름 : " << name << endl;
    cout << "나이 : " << age << endl;
  }
  ~Student()
  {
    delete []name;
    cout << "~Student 소멸자 호출!" << endl;
  }

};

int main(){
  Student st1 = Student("김철수",14);
  Student st2 = Student("홍길동",14);

  st2 = st1;
  /*
  문제점
  1. 복사가 이루어지면서 st2는 "홍길동"이 아닌 "김철수"란 문자열이 담긴 주소를 가리키고, "홍길동"이란 문자열은 접근도,소멸도 불가능해진다.
  2. 두 객체의 소멸자가 호출될 때 st1,st2 객체 모두 "김철수"란 문자열이 담긴 주소를 가리키고 delete를 통해 소멸할 때 중복 소멸하는 문제 발생
  */

  st1.ShowInfo();
  st2.ShowInfo();
  return 0;
}
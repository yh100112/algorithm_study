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
  Student& operator=(Student& ref)
  {
    delete []name;
    name = new char[10];
    strcpy(name,ref.name);
    age = ref.age;
    return *this;
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
  이렇게 하면 "홍길동"이란 문자열이 해제되지 않고 메모리 공간에 남아있는 메모리 누수 문제를 해결할 수 있고(23행),
  정의된 대입 연산자에 의해 복사가 이루어지고 st1의 "김철수"와 st2의 "김철수"는 서로 다른곳을 가리키게 되서 중복 소멸 문제가 사라진다.
  */

  st1.ShowInfo();
  st2.ShowInfo();
  return 0;
}
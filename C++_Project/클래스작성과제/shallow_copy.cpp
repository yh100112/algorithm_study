#include<iostream>
#include<string.h>
using namespace std;

class A
{
private:
  char* name;
  int age;
public:
  A(const char* myname, int myage):age(myage){
    name = new char[strlen(myname) + 1];
    strcpy(name,myname);
  }

  void ShowInfo() const{
    cout << "이름 : " << name << endl;
    cout << "나이 : " << age << endl;
  }

  ~A(){
    delete []name;
    cout << "소멸자 호출" <<endl;
  }
};

int main(){
  A a("이름",20);
  A b = a; // shallow copy로 주소값만 복사해옴 ( 디폴트 복사생성자 )
  a.ShowInfo();
  b.ShowInfo(); //객체 a의 name을 가리키는 주소 값을 b도 같이 할당받아, 두 객체가 같은 문자열을 delete해줘서 에러남
}
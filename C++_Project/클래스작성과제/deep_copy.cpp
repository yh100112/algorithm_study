#include<iostream>
#include<string.h>
using namespace std;

class A{
private:
  char* name;
  int age;
public:
  A(const char* myname, int myage): age(myage){
    name = new char[strlen(myname) + 1];
    strcpy(name,myname);
  }

  A(const A& copy): age(copy.age){
    name = new char[strlen(copy.name) + 1];
    strcpy(name,copy.name);
  }

  void showInfo() const{
    cout << "나이 : " << age << endl;
  }

  ~A(){
    delete []name;
    cout << "소멸자 호출" << endl;
  }

};

int main(){
  A a("이름",20);
  A b = a;
  a.showInfo();
  b.showInfo();

  return 0;
}
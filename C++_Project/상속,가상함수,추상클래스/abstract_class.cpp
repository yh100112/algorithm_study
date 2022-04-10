#include<iostream>
using namespace std;

class Parent{
public:
  virtual void func() = 0; 
  /* 순수 가상함수 => java의 abstract와 같은 역할
    무조건 자식클래스에서 재정의해야함
  */
};

class Child : public Parent{
public:
  void func(){ //무조건 재정의를 해야만 함
    cout << "func" << endl;
  }
};

int main(){
  Child c;

  c.func();

  return 0;
}

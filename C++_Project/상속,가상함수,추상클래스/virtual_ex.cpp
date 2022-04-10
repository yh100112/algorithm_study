#include<iostream>
using namespace std;

class Parent{
public:
  virtual void func1(){
    cout << "이곳은 parent의 func1입니다." << endl;
  }

  virtual void func2(){
    cout << "이곳은 parent의 func2입니다." << endl;
  }

  void func3(){
    cout << "이곳은 parent의 func3입니다." << endl;
  }
};

class Child : public Parent{
public:
  virtual void func1(){
    cout << "이곳은 child의 func1입니다." << endl;
  }

  virtual void func2(){
    cout << "이곳은 child의 func2입니다." << endl;
  }
};

int main(){
  Parent* p = new Parent;
  Parent* c = new Child;


  p->func1();
  c->func1();

  p->func2();
  c->func2();

  p->func3();
  c->func3();
}
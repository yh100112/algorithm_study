#include<iostream>
using namespace std;

class A
{
private:
  int num1,num2;
public:
  A(){}
  A(int num1, int num2):num1(num1),num2(num2){}
  void ShowData(){cout << num1 << ", " << num2 << endl;}
};

class B
{
private:
  int num1,num2;
public:
  B(){}
  B(int num1, int num2):num1(num1),num2(num2){}
  void ShowData(){cout << num1 << ", " << num2 << endl;}
};

int main()
{
  A a1 = A(10,50);
  A a2;
  B b1(10,20);
  B b2;

  a2 = a1;
  b2 = b1;
  /*
  우리가 대입 연산자를 정의하지 않았음에도 이런 문장은 정상적으로 멤버 대 멤버 복사가 이루어진다. 
  =>  사실 디폴트 복사 생성자와 같이, 대입 연산자가 정의되지 않으면 디폴트 대입 연산자가 삽입이 되는 것이다.
      그리고 멤버 대 멤버 복사를 수행할 때 깊은 복사가 아닌 얕은 복사를 진행한다.
  
  */

  a2.ShowData();
  b2.ShowData();
  return 0;
}
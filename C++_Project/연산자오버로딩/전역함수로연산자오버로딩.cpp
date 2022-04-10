#include <iostream>
using namespace std;

class NUMBOX{
private:
  int num1, num2;
public:
  NUMBOX(int num1, int num2) : num1(num1), num2(num2) { }
  void ShowNumber(){  
    cout << "num1: " << num1 << ", num2: " << num2 << endl;
  }

  // NUMBOX operator+(int num){
  //   return NUMBOX(num1+num, num2+num);
  // }

  friend NUMBOX operator+(int num, NUMBOX ref);
  friend NUMBOX operator+(NUMBOX ref,int num);

};

NUMBOX operator+(int num, NUMBOX ref){
  ref.num1 += num;
  ref.num2 += num;

  return ref;
}

NUMBOX operator+(NUMBOX ref,int num){
  ref.num1 += num;
  ref.num2 += num;

  return ref;
}

int main()
{
  NUMBOX nb1(10, 20);
  NUMBOX result = 10 + nb1 + 40;
  /*
    operator+(피연산자,피연산자)형태로 되므로 객체가 뒤에 위치해도 정상적으로 연산이 된다.
    즉, operator+(10,nb1)로 인식되는 것이다.
    10 + nb1 => 전역함수로 선언한 operator+(10,nb1)로 인식되서 계산되지만 그 뒤에 "객체 + 40" 형태는 전역함수로 
    선언한 operator+가 아니라 멤버함수로 선언한 operator+에 의해 객체.operator+(40)으로 인식되서 계산이 된다. 
  */
  nb1.ShowNumber();
  result.ShowNumber();
}

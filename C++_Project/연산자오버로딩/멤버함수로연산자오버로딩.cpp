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

  NUMBOX operator+(int num){
    return NUMBOX(num1+num, num2+num);
  }
};

int main()
{
  NUMBOX nb1(10, 20);
  NUMBOX result = nb1 + 10;
  /*
  NUMBOX result = 10 + nb1; 은 에러가 난다.
  => 객체.operator+(피연산자) -> 멤버함수를 통한 오버로딩은 자료형이 다른 두 대상을 연산시 반드시 객체가 왼쪽에 위치해야 연산이 가능!!
  
  =>그렇기 때문에 10+ nb1은 10.operator+(nb1)과 같은 형태로 인식되므로 10이란 정수형 데이터에 operator+란 멤버 함수도 없을 뿐더러, 
    NUMBOX객체를 매개변수로 넘기는 형태가 되었다.  
  
  <객체가 뒤에 위치해도 정상적으로 연산하도록 하기 위한 방법>
  이럴 경우는 전역 함수를 통한 오버로딩을 하면 해결된다.
  */
  nb1.ShowNumber();
  result.ShowNumber();
}

//대입 연산자 오버로딩
/*
대입 연산자 함수는, 기존의 사칙연산 연산자들 오버로딩과 다르게, 자기 자신을 가리키는 참조(Complex&)를 리턴한다.
=> 자기 자신을 가리키는 참조를 리턴하는 이유는?
    => a = b = c; 의 경우 b = c; 가 b를 리턴해야지 a = b;가 성공적으로 수행될 수 있기 때문
    => 이때 Complex가 아닌 Complex& 를 리턴하는 이유는?
        => 대입 연산 이후 불필요한 복사를 방지하기 위해서
*/
#include<iostream>
using namespace std;

class Complex{
private:
  double real, img;
public:
  Complex(double real, double img):real(real),img(img){}
  Complex(const Complex& c){ real = c.real, img = c.img;}

  Complex& operator= (const Complex& c);

  void println(){
    cout << "( " << real << " , " << img << " ) " << endl; 
  }
};

Complex& Complex::operator= (const Complex& c){ // 대입연산자(복사생성자) 연산자 오버로딩
  real = c.real;
  img = c.img;
  return *this;
}

int main(){
  Complex a(1.0,2.0);
  Complex c(0.0,0.0);
  c = a;
  c.println();
}
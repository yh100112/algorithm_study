#include <iostream>

class Complex {
private:
  double real, img;
public:
  Complex(double real, double img) : real(real), img(img) {}

  Complex& operator+(const Complex& c);
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

//사칙연산은 이렇게 반환하면 안된다!! => 참조반환이 아니라 그냥 클래스를 반환
Complex& Complex::operator+(const Complex& c){
  real += c.real;
  img += c.img;
  return *this;
}

Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real ,img * c.img);
  return temp;
}

int main() {
  Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);

  Complex c = a + b + a; // 사칙연산을 참조객체로 반환하면 이럴 때 문제 발생!!
                        // a + b를 하는 순간 a는 a+b 가 되는데 뒤에 a 가 또 있으니까 그때 a는 a+b이므로
                        //결과적으로 a+b + a+ b 가 된다.
  c.println();

}
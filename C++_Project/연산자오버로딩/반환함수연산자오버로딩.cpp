//데이터 타입 변환에 대한 연산자 오버로딩
#include<iostream>
using namespace std;

class DIV{
private:
  int num, div;

public:
  DIV(int n, int d){
    num = n;
    div = d;
  }

  operator double() const { // 변환함수에 반환형식을 지정할 수 없음
    return double(num) / double(div);
  }
  /*
  double이라는 키워드를 연산자 오버로딩하여 double값을 반환하는 함수로 오버로딩했다.
  */
};

int main(){
  DIV d(1,3);
  double db = double(d);
  cout << d;

  return 0;
}
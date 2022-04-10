#include <iostream>
using namespace std;


//private : 같은 클래스 내에서만 접근 가능
//protected : 자식 클래스랑, 자기 자신에서만 접근 가능
class Point{
private:
  int x;
  int y;

public:
  //기본 생성자 : 함수 반환형없고, 함수 이름은 클래스와 동일. 기본적으로 생성됨
  Point(){
      x = 10;
      y = 15;
  }

  //사용자지정 생성자
  Point(int x,int y){
      this->x = x;
      this->y = y;
  }

  //기본 소멸자 : 객체의 사용이 모두 끝날 때 컴파일러에서 호출하는 특수 멤버 함수. 기본생성자와 같이 기본적으로 생성됨
  ~Point(){
      cout << "소멸자 호출\n";
  }

  void print(){
    cout << "X : " <<x<<" Y : "<<y<<endl;
  }
};

int main(){
  Point p;
  p.print();

  Point p2 = {3,4}; // 사용자지정 생성자를 호출함 => Point p2(3,4) 이것도 가능!!
  p2.print();

  Point p3 = Point(5,5);
  p3.print();
  
  return 0;

}
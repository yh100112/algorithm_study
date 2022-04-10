#include<stdio.h>
#include<stdlib.h>
using namespace std;

//구조체를 이용한 객체 생성방법
struct Point2D{
  int x;
  int y;

  void init(int x, int y){
    this->x = x;
    this->y = y;
  }

  void printPoint2D(){
    printf("(%d, %d)\n",x,y);
  }

};

int main(){
  //첫번째 방법 : 선언과 동시에 멤버변수 초기화
  struct Point2D p1 = {1,0};
  p1.printPoint2D();

  //두번째 방법 : 선언 후 멤버변수 초기화
  struct Point2D p2;
  p2.x = 4;
  p2.y = 5;
  p2.printPoint2D();

  //세번째 방법 : 선언 후 멤버변수 초기화
  struct Point2D p3;
  p3.init(3,5);
  p3.printPoint2D();

  return 0;
}
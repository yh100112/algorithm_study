#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Pony
{
private:
  string memoryLocation;
  string num;

public:
  Pony(string str){};
  ~Pony(){};
  void setNum(string str){ num = str;}
  string getNum(){
    return num;
  }
};

// int main(){
//   Pony stackPony("STACK");
//   stackPony.setNum("Second");
//   cout << stackPony.getNum() << "Pony is on stack Memory." << endl;
//   /*
//   선언만으로도 stackPony 인스턴스가 생성되어 스택 영역에 올라간다.
//   .연산자를 통해 인스턴스에 접근할 수 있다.
//   스택 메모리의 데이터는 함수 영역을 벗어나면 자동으로 소멸되기 때문에, 메모리 해제가 따로 필요없다.
//   */


//   return 0;
// }
int main(){
  Pony* heapPony = new Pony("First");

  // heapPony->setNum("First");
  cout << heapPony->getNum() << "Pony is on heap Memory." << endl;

  delete heapPony;

  return 0;
  /*
  new는 메모리할당, 생성자 호출, 타입변환 까지 총 세가지 일을 한다.
  동적 할당 시에는 ->로 포인터에 접근한다.
  delete는 소멸자를 자동으로 호출하고 메모리를 해제하는 두가지 일을 한다.
  */
}
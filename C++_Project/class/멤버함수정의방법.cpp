#include<iostream>
using namespace std;

class member{
private:
  int id;
  string name;

public:
  member();

  //멤버 함수 정의방법 1. 내부 클래스 정의
  void print_name(){
      cout << name;
  }

  //2. 외부 클래스 정의
  void print_id();

  void print(int val);
};

//1.외부 클래스 정의
member::member(){
  printf("생성자 외부에서정의\n");
}

void member::print(int val){
  printf("%d\n",val);
}

//2.외부 클래스 정의
void member::print_id(){
  cout << id;
}



int main(){ 
  member m1;
  m1.print(3);
  return 0;
}
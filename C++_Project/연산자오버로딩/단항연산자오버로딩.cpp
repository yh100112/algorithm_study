//증가,증감 연산자의 오버로딩
//후위 증가와 전위 증가는 어떻게 구분을 할까?
#include<iostream>
using namespace std;

class NUMBOX{
private:
  int num1,num2;
public:
  NUMBOX(){}
  NUMBOX(int num1, int num2) : num1(num1), num2(num2){}
  void ShowNumber(){
    cout << "num1 : " << num1 << ", num2 : " << num2 << endl;
  }
  NUMBOX operator++(){ // 전위 증가 형식
    num1 += 1;
    num2 += 1;
    return *this;
  }
  NUMBOX operator++(int){ // 후위 증가 형식
    NUMBOX temp = NUMBOX(*this); // 기존의 객체를 저장 
    num1 += 1;
    num2 += 1;
    return temp; // num1,num2를 증가시킨 현재 *this가 아닌 증가시키기 전의 객체를 반환해서 후위 연산을 구현함
  }
};

int main(){
  NUMBOX nb1 = NUMBOX(10,20);
  NUMBOX nb2;

  nb2 = nb1++;
  nb2.ShowNumber(); // 10,20
  nb1.ShowNumber(); // 11,21

  nb2 = ++nb1;
  nb2.ShowNumber(); // 12,22
  nb1.ShowNumber(); // 12,22
}
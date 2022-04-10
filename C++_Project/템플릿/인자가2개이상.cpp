#include<iostream>
#include<string>

using namespace std;

template<typename T1, typename T2>
void printAll(T1 a, T2 b){
  cout << "T1 : " << a << endl;
  cout << "T2 : " << b << endl;
};

int main(){
  char* s1 = "Dok2";
  char* s2 = "On MY WAY";

  int num1 = 27;
  int num2 = 35;

  double d1 = 3.14;
  double d2 = 36.5;

  printAll(s1,s2);
  printAll(s1,num1);
  printAll(num1,num2);
  printAll(num1,d1);
  printAll(d1,d2);
  printAll(d1,s1);

  return 0;
}
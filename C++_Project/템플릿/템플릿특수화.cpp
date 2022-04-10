#include<iostream>
#include<string>
using namespace std;

template <typename T>
T sum(T a, T b){
  return a+b;
}

template<>
char* sum<char*>(char* s1, char* s2){
  char *str = "char* 문자열은 더할 수 없습니다.";
  printf("%s\n",s1);
  printf("%s\n",s2);
  return str;
}

template<>
const char* sum<const char*>(const char* s1,const char* s2){
  char *str = "char* 문자열은 더할 수 없습니다.";
  printf("%s\n",s1);
  printf("%s\n",s2);
  return str;
}

template<>
string sum<string>(string s1, string s2){
  string str = "char* 문자열은 더할 수 없습니다.";
  cout << s1 << endl;
  cout << s2 << endl;

  return str;
}

int main(void){
  int a =10;
  int b =20;
  double d1 = 1.1;
  double d2 = 2.2;
  char * s1 = "Dok2 ";
  char * s2 = "On My Way.";
  string s3 = "ZICO";
  string s4 = "Double D";
  cout << sum(a, b) << endl << endl;

  cout << sum(s1, s2) << endl << endl;
  cout << sum<const char*>(s1, s2) << endl << endl;
  cout << sum(s3, s4) << endl;

  return 0;
}


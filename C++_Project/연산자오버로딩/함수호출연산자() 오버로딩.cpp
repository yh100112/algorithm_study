#include<iostream>
using namespace std;

class wowcat
{
public:

  //정의방법1
  int operator() (int iArg1, int iArg2){
    int iNum = iArg1 + iArg2;

    return iNum;
  }

  //정의방법2
  int operator()(int, int, int);
};

int wowcat::operator()(int iArg1, int iArg2, int iArg3){
  int iNum = iArg1 + iArg2 + iArg3;
  return iNum;
}

int main(){
  wowcat Obj1;

  cout << "사용법 1-1 : " << Obj1.operator()(1,2) << endl;
  cout << "사용법 1-2 : " << Obj1(2,3) << endl << endl;

  cout << "사용법 2-1 : " << Obj1.operator()(1,2,3) << endl;
  cout << "사용법 2-2 : " << Obj1(1,2,3) << endl << endl;
}
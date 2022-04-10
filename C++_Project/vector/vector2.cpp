#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  vector<string> v;

  v.push_back("Show Me");
  v.push_back("Tiger JK");
  v.push_back("Dok2");
  v.push_back("GAEKO");
  v.push_back("ZICO");

  //ex1) v.front(), v.back()
  cout << "//ex1) v.front(), v.back()" << endl;
  cout << "v.front() : " << v.front() << endl;
  cout << "v.end() : " << v.back() << endl;
  cout << endl;

  //ex2) v.popback()
  cout << "//ex2) v.popback()" << endl;

  vector<string>::iterator iter;
  for(iter = v.begin(); iter != v.end(); iter++){
    cout << *iter << " / ";
  }
  cout << endl;

  v.pop_back();

  for(iter = v.begin(); iter != v.end(); iter++){
    cout << *iter << " / ";
  }
  printf("\n\n");

}
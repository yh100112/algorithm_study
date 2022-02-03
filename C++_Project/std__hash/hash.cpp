#include<iostream>
#include<iomanip>
#include<functional>
#include<string>
#include<vector>
using namespace std;

int main(){
  string str1("arbitrary string");
  vector<string> vec2 = {"true","false","false","true","false","true"};

  hash<string> str_hash; // 해시함수 객체 생성

  cout << "hash(str1) - " << str_hash(str1) << endl;

  cout << "hash(vec2 elements) - ";
  for(auto& item : vec2){
    cout << str_hash(item) << ", ";
  }
  printf("\n");

  return 0;
}

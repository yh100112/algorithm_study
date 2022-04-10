#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,int> um;

int main(){
  um["bts"] = 1;
  um["kfc"] = 2;
  um["bbq"] = 3;
  um["qqq"] = 4;

  string str;
  cin >> str;

  if(um.count(str) > 0){
    cout << "발견";
  }else{
    cout << "미발견";
  }
}
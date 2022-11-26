#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main() {
  stringstream ss("1 2 3 4"); // ss에서 추출하는 건 공백, \n을 기준으로만 됨
  int num;
  while (ss >> num) {
    cout << num << endl; // 1 2 3 4
  }
  cout << endl;

  string arr = "[1,2,3,4]";
  arr.erase(0,1);                 // 문자열 특정 부분 지우기 -> 첫 문자
  arr.erase(arr.length() - 1, 1); // 문자열 특정 부분 지우기 -> 마지막 문자

  stringstream ass(arr);
  string token;
  while(getline(ass, token, ',')) { // ' '만 됨, " "는 안 됨, 두번째 인자는 무조건 string
    cout << stoi(token) << endl;
  }

}
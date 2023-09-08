#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
  std::string str = "Hello World";
  // std::transform(str.begin(), str.end(), str.begin(), toupper);
  // char a = toupper(str[1]);
  cout << (int)toupper(str[1]) << endl;;
  // std::cout << str << std::endl;
  return 0;
}

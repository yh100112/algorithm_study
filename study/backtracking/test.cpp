#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  vector<string> a;
  
  int n;
  for(int i = 0; i < 3; i++){
    string input;
    getline(cin, input);
    a.push_back(input);
  }

  cout << "------------" << endl;
  for(auto& v: a)
    cout << v << endl;
}
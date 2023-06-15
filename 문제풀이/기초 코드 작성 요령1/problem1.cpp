#include<iostream>
using namespace std;

void func1(int n){
  int sum = 0;
  for(int i = 1; i <= n; i++){
    if(i % 3 == 0 || i % 5 == 0){
      sum += i;
    }
  }

  cout << sum << endl;
  return;
}

int main(){
  func1(34567);
}
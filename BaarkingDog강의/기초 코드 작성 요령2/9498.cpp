#include<iostream>
using namespace std;

int main(){
  int score;
  cin >> score;

  if(90 <= score && score <= 100){
    cout << "A" << "\n";
  }else if(80 <= score && score <= 89){
    cout << "B" << "\n";
  }else if(70 <= score && score <= 79){
    cout << "C" << "\n";
  }else if(60 <= score && score <= 69){
    cout << "D" << "\n";
  }else{
    cout << "F" << "\n";
  }
}
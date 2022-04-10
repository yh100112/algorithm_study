#include<iostream>
using namespace std;

class Temporary{
private:
  int num;
public:
  Temporary(int n): num(n){
    cout<<"create obj : " << num << endl;
  }
  ~Temporary(){
    cout << "destroy obj : " << num << endl;
  }
  void ShowTempInfo(){
    cout << "My num is " << num << endl;
  }
};

int main(){
  Temporary(100);
  printf("------------------------\n");
  Temporary(200).ShowTempInfo();
  printf("------------------------\n");
  return 0;
}
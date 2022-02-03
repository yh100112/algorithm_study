#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;

  for(int i=0;i<7;i++){
    v.push_back(10*i); // 0 10 20 30 40 50 60
  }

  vector<int>::iterator iter;
  iter = v.begin();

  cout << &iter << endl; //0x7ffde9fed398
  cout << *iter << endl; // 0


  //임의 접근
  cout << iter[1] << endl; // 10

  iter += 2;
  cout <<&iter << endl;  //0x7ffde9fed398
  cout << *iter << endl; // 20
  cout << iter[0] << endl; // 20

  for(iter = v.begin(); iter != v.end(); iter++){
    cout <<*iter << " ";
  }
  printf("\n");

  return 0;
}

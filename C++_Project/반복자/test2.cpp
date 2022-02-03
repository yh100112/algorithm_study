#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  vector<int>::iterator iter;
  iter = v.begin();

  for(iter = v.begin(); iter != v.end(); iter++){
    cout << *iter << " ";
  }
  printf("\n");
  //여기서 현재 iterator는 v.end()를 가리킴

  iter = v.begin(); // iter를 다시 v.begin()을 가리키도록 바꿈

  //임의접근
  cout << "iter[0] : " <<  iter[0] << endl;
  cout << "iter[3] : " << iter[3] << endl << endl;

  //iterator는 v.begin() + 2 (즉, 3번째 원소)를 가리킴
  cout << "iterator가 3번째 원소를 가리키도록 변경" << endl;
  iter += 2;
  cout << "iter[0] : " << iter[0] << endl;
  cout << "*iter : " << *iter << endl;

  //반복자를 통한 원소 값 변경
  *iter = 10;
  *(iter+1) = 20;
  iter[2] = 30;

  for(iter = v.begin(); iter != v.end(); iter++){
    cout << *iter << " ";
  }
  cout << endl;

  return 0;

}
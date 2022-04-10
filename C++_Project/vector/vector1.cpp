#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;

  v.push_back(21);
  v.push_back(32);
  v.push_back(53);
  v.push_back(64);
  v.push_back(15);

  //ex1) 멤버형식 size_type을 이용한 반복
  cout << "ex1-1) [v.at(i)] size_type : ";
  for(vector<int>::size_type i = 0; i < v.size(); i++){
    cout << v.at(i) << " ";
  }

  cout << endl;

  cout << "ex1-2) [ v[i] ] size_type : ";
  for(vector<int>::size_type i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }

  printf("\n\n");

  //ex2) int i 를 이용한 반복
  cout << "ex2-1) [v.at(i)] int : ";
  for(int i = 0; i < v.size(); i++){
    cout << v.at(i) << " ";
  }
  cout << endl << endl;

  //ex3) 반복자 iterator를 이용한 반복
  cout << "ex3) [*iter] iterator : ";
  vector<int>::iterator iter;
  for(iter = v.begin(); iter != v.end(); iter++){
    cout << *iter << " ";
  }

  printf("\n\n");

}
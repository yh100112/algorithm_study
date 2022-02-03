#include<iostream>
#include<list>
using namespace std;

int main(){
  list<char> alpha_list;

  for(char c = 'a'; c <= 'z'; c++){
    alpha_list.push_back(c);
  }

  while(alpha_list.empty() != 1){
    cout << alpha_list.front() << " ";
    alpha_list.pop_front();
  }
  printf("\n");

  return 0;
}
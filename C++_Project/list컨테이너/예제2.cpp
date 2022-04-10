#include<iostream>
#include<list>
using namespace std;

int main(){
  list<char> alpha_list;

  for(char c = 'a'; c<= 'n'; c++){
    alpha_list.push_back(c);
  }

  list<char>::iterator it;
  for(it = alpha_list.begin(); it != alpha_list.end(); it++){
    if(*it == 'm') alpha_list.erase(it++); // alpha_list.erase(it)만 하면 erase를 실행후에 반복자 it의 값은 엉뚱한 곳을 가리키게 된다.
    if(*it == 'n') alpha_list.erase(it++);
  }

  for(it = alpha_list.begin(); it != alpha_list.end(); it++){
      printf("%c ",*it);
  }
  printf("\n");
  printf("%d\n",alpha_list.size());
  return 0;
}
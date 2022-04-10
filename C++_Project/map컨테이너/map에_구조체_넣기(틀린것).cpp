#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
using namespace std;

struct File{
  int a = 2;
  int b = 3;
  char* read_curr_ptr = (char*)&a;
};

int main(){
  map<int,struct File> m;
  struct File f;
  printf("%p %p\n",&f.a,f.read_curr_ptr); 

  m[1] = f;
  /*
  선언한 구조체 객체 f와 내용만 똑같이 복사한 전혀 다른 구조체 f를 대입연산자로 value로 넣음 
    -> 이 때 복사본에서의 변수 a,b는 선언 당시 주소값을 대입한게 아닌 그냥 값을 대입한 것이므로 복사본에서도 문제가 되지 않는데, 
    read_curr_ptr은 선언할 때 선언할 때의 구조체 안에 있는 a의 주소값을 넣는다.그런데 복사본은 원래 구조체의 값들을 그대~로 복사한 복사본이다. 그러므로
    복사본에서의 read_curr_ptr은 처음 f를 만들 때의 a의 주소값을 그대로 복사한거라 복사본 구조체의 read_curr_ptr에는 복사본의 변수 a의 주소가 아닌
    위에서 구조체 객체 f를 처음 선언했던 당시의 원본 구조체 안에 있는 a의 주소값이 들어 있다.
  */
  /*
    위에서 출력한 주소값과 아래에서 출력한 m[1].read_curr_ptr의 주소값이 같다. 하지만 &m[1].a의 주소값은 다르다. 그래서 epoll2차과제 추가수정에서 변수의 주소가 서로 달라 
    읽어와도 저장이 내가 원하는 변수에 저장이 안되고 이상한 주소에 저장이 됐던 것이다.
  */
  printf("%p %p\n",&m[1].a,m[1].read_curr_ptr); 

  

  return 0;
}
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<unordered_map>
#include<string>
using namespace std;

//key
struct Person{
  string first, last;

  Person(string f, string l){
    first = f;
    last = l;
  }
};

//hash함수  => 실제 해시값을 비교할 때는 내부적으로 이 값을 사용함. 사용자가 직접적으로 이값을 쓰진 않는다.
struct MyHashFunction{
  size_t operator() (const Person& p) const{
    return p.first.length() + p.last.length();
  }
};

struct KeyEqual{
  bool operator() (const Person& p1, const Person& p2) const {
    cout << p1.first <<  " | " << p2.first << endl;
    return p1.first == p2.first && p1.last == p2.last;
  }
};

int main(){
  unordered_map<Person, int, MyHashFunction,KeyEqual> um;
  Person p1("김덕용", "1997 born");
  Person p2("김길동", "1000 born");
  Person p3("홍홍홍", "1997 born");


  um.insert({p1,100});
  um.insert({p2,200});
  um.insert({p3,300});
  um.insert({p3,1000});


  for(auto e : um){
    cout << "[" << e.first.first << ", "
          << e.first.last << "] => " << e.second << '\n';
  }
}

/*
unordered_map의 4번째 인자인 KeyEqual은 해시맵에 값을 넣을 때마다 동작한다.
해시맵의 값이 1개만 들어있을 땐 해시값이 충돌할 일이 없으므로 해시 충돌 처리를 해야 하는 KeyEqual이
동작하지 않는다. 하지만 해시맵에 값이 2개 이상일 때는 넣을 때마다 해시맵에 들어있는 다른 데이터의 해시값과
충돌이 일어날 수 있으므로 값을 넣기 전에 해시값을 비교한다. 그 부분이 바로 KeyEqual의 operator ()이다.
코드 동작 순서대로 한다면
1. 김길동을 넣을 때   =>  김길동 | 김덕용  ( 기존에 이미 있던 p1(김덕용)과 해시값을 비교함 )
2. 홍홍홍을 넣을 때   =>  홍홍홍 | 김길동 , 홍홍홍 | 김덕용 순서로 동작됨 ( 기존에 이미 있는 것 중 가장 최근에 들어간 해시값과 먼저 비교함 )

이런 식으로 값이 들어가기 전 이미 있는 데이터들의 해시값과 비교해서 true를 반환하면 이미 해시값이 존재하는 것이므로
값을 덮어씌우고, false인 경우는 새롭게 값을 넣는다.
*/ 
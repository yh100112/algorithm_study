#include<iostream>
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

  //해시 충돌 처리를 위해 구현 (그냥 이 형태 외우자!!)
  bool operator == (const Person& p) const{
    cout << p.first <<  " | " << first << endl;
    return first == p.first && last == p.last;
  }
};

//hash함수
struct MyHashFunction{
  size_t operator() (const Person& p) const{
    return p.first.length() + p.last.length();
  }
};

// struct MyHashFunction{
//   size_t operator() (const Person& p) const{
//     return (hash<string>()(p.first)) ^ (hash<string>()(p.last)); // ^ == || (xor연산)
//   }
// };

int main(){
  unordered_map<Person, int, MyHashFunction> um;
  Person p1("kartik", "kapoor");
  Person p2("Ram", "Singh");
  um[p1] = 100;
  um[p2] = 200;

  for(auto e : um){
    cout << "[" << e.first.first << ", "
          << e.first.last << "] => " << e.second << '\n';
  }

  if(um.count(p2) > 0) printf("발견\n");

}
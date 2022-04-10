#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

template<typename T>
struct NODE {
  T data;
  NODE<T>& next;

  NODE(const T& a, NODE<T>* ptr){
    data = a;
    next = ptr;
  }

};

template<typename T>
class MyIterator{
private:
  NODE<T>* cur;
public:
  MyIterator(NODE<T>* p = nullptr):cur(p){}
  
  MyIterator& operator ++ (){
    cur = cur->next;
    return *this;
  }

  T& operator * (){
    return cur->data;
  }

  bool operator == (const MyIterator& ref){
    return cur == ref.cur;
  }

  bool operator != (const MyIterator& ref){
    return cur != ref.cur;
  }
};

template<typename T>
class MyList{
private:
  NODE<T>* head;
public:
  MyList():head(nullptr){}
  void push_front(const T& a){
    head = new NODE<T>(a,head);
  }

  typedef MyIterator<T> iterator;

  iterator begin(){
    return iterator(head);
  }

  iterator end(){
    return iterator(nullptr);
  }
};



int main(){
  MyList<int> list;
  list.push_front(10);
  list.push_front(20);
  list.push_front(30);

  MyList<int>::iterator itor = list.begin();

  for(;itor != list.end(); ++itor){
    cout << *itor << endl;
  }
}
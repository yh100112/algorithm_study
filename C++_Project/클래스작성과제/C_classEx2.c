#include<stdio.h>
#include<stdlib.h>

typedef struct Parent{
  struct Parent *this; // this포인터
  //멤버변수
  int money_;
  //멤버함수
  void (*PrintInfo)(struct Parent *this); // 함수포인터 이용
  //접근함수
  int (*get_money)(const struct Parent *this);
  void (*set_money)(struct Parent *this, int money);
}parent;

//생성자,소멸자
parent *NewParent(int money);
void DeleteParent(struct Parent *parent_ptr);

//함수 외부 선언
void PrintInfo_(const struct Parent *this);
int get_money_(const struct Parent *this);
void set_money_(struct Parent *this, int money);

parent *NewParent(int money){
  parent *temp = (parent*)malloc(sizeof(parent));
  temp->money_ = money;

  //함수 포인터 등록
  temp->this = temp;
  temp->PrintInfo = PrintInfo_;
  temp->get_money = get_money_;
  temp->set_money = set_money_;
  return temp;
}

void DeleteParent(struct Parent *parent_ptr){
  free(parent_ptr);
}

void PrintInfo_(const struct Parent *this){
  printf("현재 돈 : %d\n",this->money_);
}

int get_money_(const struct Parent *this){
  return this->money_;
}

void set_money_(struct Parent *this, int money){
  this->money_ = money;
}

int main(){
  int money;


  //생성자 따라하기
  parent *parent_ptr = NewParent(10000);

  printf("처음에 가진 돈은 아래와 같습니다.\n");
  parent_ptr->PrintInfo(parent_ptr);

  parent_ptr->set_money(parent_ptr, 40000);

  printf("\n변화된 돈은 아래와 같습니다.\n");
  parent_ptr->PrintInfo(parent_ptr);

  money = parent_ptr->get_money(parent_ptr);
  printf("\n가져온 돈은 %d원입니다.\n",money);

  //소멸자 따라하기
  DeleteParent(parent_ptr);

  return 0;
}





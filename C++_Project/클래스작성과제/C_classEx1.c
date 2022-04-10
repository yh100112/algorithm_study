#include<stdio.h>
#include<stdlib.h>

typedef struct Person{
  struct Person *this; // this를 구현

  //멤버변수, 필드
  int age_;
  int money_;

  //멤버함수, 메서드
  void (*SayAge)(const struct Person* this);

  //접근함수, 액세스 메서드
  int (*get_money)(const struct Person* this);
  void (*set_money)(struct Person* this, int money);
}Persson;

Persson *newPerson(int age,int grade);
void DeletePerson(struct Person *person_ptr);

void SayAge_(const struct Person *this);
int get_money_(const struct Person *this);
void set_money_(struct Person* this, int grade);

//생성자 역할
Persson *NewPerson(int age, int money){
  Persson* tmp = (Persson*)malloc(sizeof(Persson)); // 메모리를 힙에 할당하고 객체 초기화
  tmp->age_ = age;
  tmp->money_ = money;

  //함수포인터 등록하고 외부함수를 메서드에 등록
  tmp->this = tmp;
  tmp->SayAge = SayAge_;
  tmp->get_money = get_money_;
  tmp->set_money = set_money_;

  return tmp;
}

//메모리를 해제시키는 역할 ( 소멸자 )
void DeletePerson(struct Person *person_ptr){ 
  free(person_ptr); 
}

void SayAge_(const struct Person *this){ 
  printf("%d\n",this->age_);
}

int get_money_(const struct Person *this){ 
  return this->money_; 
}

void set_money_(struct Person* this, int money){ 
  this->money_ = money;
}

int main(){
  Persson* person = NewPerson(15,90);

  person->SayAge(person);
  person->set_money(person,80);

  int money = person->get_money(person);
  printf("%d\n", money);

  DeletePerson(person);
  return 0;
}

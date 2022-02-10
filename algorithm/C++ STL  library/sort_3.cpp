// ! 실무에서 실제로 sort()를 사용하는 경우

#include<iostream>
#include<algorithm>

using namespace std;

class Student{
public:
  string name;
  int score;
  Student(string name, int score){
    this->name = name;
    this->score = score; 
  }

  //정렬 기준 : 점수가 작은 순서
  // 다른 학생(student)과 비교할 때 내 점수(this->score)가 더 낮다면
  // 우선순위가 높다라는 뜻 => 점수가 작은 순서부터 출력하겠다는 말임
  bool operator < (Student& student){
    return this->score < student.score;
  }

};

int main(){
  Student students[] = {
    Student("나동빈", 90),
    Student("이상욱", 93),
    Student("박한울", 97),
    Student("강종구", 87),
    Student("이태일", 92)
  };
  sort(students,students + 5); // 클래스 내에서 기준을 정해줬기 때문에 이렇게 시작값과 끝값만 써주면 됨
  for(int i = 0; i < 5; i++){
    cout << students[i].name << " ";
  }
}
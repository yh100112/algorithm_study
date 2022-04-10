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

  bool operator < (Student& student){
    return this->score < student.score;
  }

};

int main(){
  Student students[] = {
    Student("김일병", 90),
    Student("김이병", 93),
    Student("김상병", 97),
    Student("김사병", 87),
    Student("김오병", 92)
  };
  sort(students,students + 5); 
  for(int i = 0; i < 5; i++){
    cout << students[i].name << " ";
  }
}
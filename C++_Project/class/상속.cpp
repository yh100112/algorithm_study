#include<iostream>
#include<string>

using namespace std;

class Person{
private:
    string name;
public:
    Person(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }

    void showName(){
        cout << "이름 : " <<getName() << '\n';
    }
};

class Student : public Person{ 
private:
    int studentID;
public:
    Student(int studentID,string name) : Person(name) {
        this->studentID = studentID;
    }

    void show(){
        cout << "학생번호 : " << studentID << '\n';
        cout << "학생이름 : " << getName() << '\n'; //자식클래스 내부에서 부모클래스의 함수에 접근하는 것은 상속할 때public Person을 안 써도 가능하다.하지만 메인에서 사용할 때는 접근할 수 없다.
    }

    //오버라이드
    void showName(){
        cout << "학생 이름 : " << getName() << '\n';
    }

};

int main(){
    Student student(1,"김덕용");
    student.show();
    student.showName();//  클래스의 기본 접근제어관한은 private이라서 public Person을 써주지 않으면 자식 클래스로 선언한 객체에서 부모클래스의 함수를 접근할 수 없다.
    return 0;
}
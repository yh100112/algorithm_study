#include<iostream>
#include<iomanip>
#include<ios>
#include<string>

using namespace std;

int main(){
    //학생의 이름을 입력받음
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    //중간시험과 기말시험의 점수를 입력받음
    cout << "Please enter your midterm and final exam grades: ";
    double midterm,final;
    cin >> midterm >> final; //cin >> midterm
                            // cin >> final  과 같은 문장임 cout처럼 이어서 쓸 수 있음

    //과제 점수를 물음
    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";

    //지금까지 입력된 과제 점수의 개수와 합
    int count = 0;
    double sum = 0;

    //입력을 위한 변수
    double x;

    //불변성: 지금까지 count개 점수를 입력받았으며 입력받은 점수의 합은 sum
    while(cin >> x){ // 입력을 한 칸 띄고 쓰면 계속 입력받는 게 됨 ->enter치고 ctrl+d로 종료하면 입력 끝
        count++;
        sum += x;
    }

    streamsize prec = cout.precision(); // 원래의 정밀도가 저장되어있음
    cout << "Your final grade is " << setprecision(3)
        <<midterm + final + sum
        << setprecision(prec) << endl;      //setprecision(3)으로 스트림을 조작하고 난 후, 다시 setprecision을 사용해서 cout에 있을지 모르는 후속 출력의 정밀도를 원래 상태로 돌려놓는다 (이게 좋은 프로그래밍 습관이다)
                                            //이 코드는 cout의 마지막 부분이라 출력의 후속부분이 없지만, 이런 습관을 가지자.
    
    return 0;
}















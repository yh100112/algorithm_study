#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter your first name : ";
    string name;
    cin >> name; // 입력을 name에 저장

    const string greeting = "Hello, " + name + "!"; //출력하려는 메세지

    //두번째 행, 4번째 행
    const string spaces(greeting.size(), ' '); // 문자열 상수 spaces는 쉼표로 구분하고 괄호로 묶인 2개의 표현식을 사용하여 초기화했음
    const string second = "*" + spaces + "*";

    //첫번째 행, 5번째 행
    const string first(second.size(), '*'); // 문자열 상수 first는 쉼표로 구분하고 괄호로 묶인 2개의 표현식을 사용하여 초기화했음
    // const string star(10,'h');

    cout << endl;
    cout << first << endl;
    cout << second << endl;
    cout << "*" << greeting << "*" << endl;
    cout << second << endl;
    cout << first << endl;

    return 0;
}
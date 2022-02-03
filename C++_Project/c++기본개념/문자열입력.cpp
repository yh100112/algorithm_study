#include <iostream>
#include <string>

using namespace std;

int main(){
    // std::cout << "Please enter your first name : "; // endl이 없으면 메시지를 출력한 후 행 바꿈을 하지 않고 동일한 행에서 입력을 기다림.
    
    // //이름을 읽어들임
    // std::string name;
    // std::cin >> name;

    // std::cout << "Hello, " << name << "!" << std::endl;

    //띄어쓰기도 다 입력받고 싶을 때 getline사용
    string address, name;

    cout << "자신의 이름을 적어주세요 : ";

    getline(cin, name);

    cout << "자신이 살고 있는 도시를 적어주세요 : ";

    getline(cin, address);

    cout << address << "에 살고 있는 " << name << "님~ 감사합니다!";

    return 0;
}
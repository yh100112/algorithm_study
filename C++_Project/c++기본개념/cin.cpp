#include<iostream>

using namespace std;

int main(){
    int a;
    /*
    while(true){
        cin >> a;
        if(cin.fail()){
            cout << "비정상입력!"<< endl;
        }
    } 이 경우 문자를 입력하면 cin.fail()이 버퍼 안에 문자가 계속 남아있으므로 true가되서 계속 비정상입력이 출련된다.
    */

/*
    while (true)
    {
        cin >> a; //사용자에게 입력을 받지 않고 또다시 버퍼에 남아있는 문자를 읽어들여  clear로 failbit를 초기화해도 문제가발생
        if (cin.fail())
        {
            cout << "비정상입력!" << endl;
            cin.clear()
        }
    } clear를 하면 failbit를 초기화 하지만 버퍼 안에 남아있는 문자는 그대로이므로 이것도 게속 비정상입력이 출력된다.
*/


    while(true){
        cin >> a;
        if(cin.fail()){
            cout << "비정상입력!" << endl;
            cin.clear();//플래그들을 초기화(goodbit,badbit,eofbit,failbit를 초기화)
            cin.ignore(5, '\n'); // 문자 5개 읽고 버리거나 '\n'을 읽어들이면 버린다. => 이렇다면 거기까지만 읽고 버퍼를 비워준다.
        }
    }
}
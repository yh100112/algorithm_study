#include<iostream>

using namespace std;

void Local(int*);

int main(){
    int var = 10;
    cout << "초기 : " << var << endl;

    Local(&var);
    cout << "Local()함수 호출 후 변수 var의 값 : " << var << endl;
    return 0;
}

//var가 보유하고 있는 주소를 새로운 변수 num에 저장하는 것이다.
//num을 역참조해서 그 값을 바꾸면 당연히 원래의 var값이 바뀐다.
void Local(int* num){
    *num = 20; // 역참조
}
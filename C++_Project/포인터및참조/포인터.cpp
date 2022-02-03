#include<iostream>

using namespace std;

int main(){
    int num1 = 1234;
    double num2 = 3.14;

    int *ptr_num1 = &num1;
    double *ptr_num2 = &num2;

    cout << "포인터 변수의 크기는 " << sizeof(ptr_num1) << "입니다." << endl;  // 8바이트
    cout << "포인터의 크기는 " << sizeof(*ptr_num1) << "입니다." << endl; // 변수 n의 값이므로 그 값(int)의 크기인 4바이트가 나온다.
    cout << "포인터 ptr_num1이 가리키고 있는 주소값은 " << ptr_num1 << " "<<&num1<<"입니다." <<endl;
    cout << "포인터 ptr_num1이 가리키고 있는 주소에 저장된 값은 " << *ptr_num1 << "입니다." << endl;
    cout << "포인터 ptr_num2가 가리키고 있는 주소값은 " << ptr_num2 << "입니다." << endl;
    cout << "포인터 ptr_num2가 가리키고 있는 주소에 저장된 값은 " << *ptr_num2 << "입니다.";

    return 0;
}
#include<iostream>
using namespace std;

int main(){

    //1바이트만큼 heap에 공간 할당
    char* pchar = new char;
    *pchar = 'a';
    cout << "메모리주소 :" << (void*)pchar << "\t값 : " << *pchar << endl; //char만 좀 특별하게 void*써줘야 포인터변수가 담고있는 주소값이 보임
    cout << "heap크기 :" << sizeof(*pchar) << endl;
    delete pchar;

    //4바이트만큼 heap에 공간 할당
    int* pnum = new int;
    *pnum = 3;
    cout << "메모리주소 :" << pnum << "\t값 : " << *pnum << endl;
    cout << "heap크기 :" << sizeof(*pnum) << endl;
    delete pnum;

    //8바이트만큼 heap에 공간 할당
    double* pdouble = new double;
    *pdouble = 3.1415;
    cout << "메모리주소 :" << pdouble << "\t값 : " << *pdouble << endl;
    cout << "heap크기 :" << sizeof(*pdouble) << endl;
    delete pdouble;

    //string 동적할당
    string *line = new string;
    *line = "hello";
    cout << *line << endl;
    delete line;

    return 0;

}
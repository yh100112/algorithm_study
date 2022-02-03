#include<iostream>
#include<malloc.h>
using namespace std;

int main(){
    // int *point = new int; //메모리 할당
    // *point = 100;

    // cout <<*point;

    // delete point; // 메모리 해제

    // 배열 형태의 메모리 할당 및 해제
    int *point = new int[5]; // 배열 형태 메모리 동적할당

    for(int i=0; i<5; i++){
        point[i] = i;
    }

    for(int i=0; i<5; i++){
        cout << point[i] << endl;
    }
    cout << sizeof(point) << endl; // 8바이트
    cout << sizeof(*point) <<endl; // 4바이트
    cout << sizeof(point[0]) << endl; // 4  이것도값이니까 정수이므로 4바이트
    cout << *point<<endl; // 0

    delete[] point; // 배열 형태 메모리 할당해제

    double *a = new double;
    cout << sizeof(a) << endl; // 8
    cout << sizeof(double) << endl; // 8
    cout << sizeof(int) << endl; // 4

    delete a;

    return 0;
}
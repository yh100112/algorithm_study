#include<iostream>
using namespace std;

int main(){
    int arr[3] = {1,2,3};

    cout << arr << endl; // 배열의 시작값 주소 나옴
    int length = sizeof(arr) / sizeof(arr[0]); // 배열의 길이 구하는 공식 

    for(int i = 0; i < length ; i++){
        cout << arr[i] << endl;
    } //배열 요소 출력

    string arr2[3] = {"a","b"}; //""로 되어있으므로 문자열이라 32바이트이다. 문자아님!
    string l;
    char a;
    cout << sizeof(l) << endl; // string은 32바이트이다.
    cout << sizeof(a) << endl; // char는 1바이트이다.
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "마지막 값 : "<< arr2[2] << endl; // null 자동으로 들어감

    return 0;
}
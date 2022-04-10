#include<iostream>
using namespace std;

void printArray(const int* array, int length){


    for(int index=0;index < length; index++){
        cout << array[index] << " ";
    }
}

int main(){
    int array[6] = {6,5,4,3,2,1};
    printArray(array,6); // 배열은 이름만 써도 그 자체가 배열의 시작 주소를 나타내므로 &를 안씀
                        //배열이 함수에 전달될 때 포인터로 변환되므로 길이를 구할 수 없다.그러므로 별도로 길이를 보내줘야한다.
                        //ex) 동적할당으로 배열 선언할 때 길이 구할수 없는 것처럼
    return 0;
}
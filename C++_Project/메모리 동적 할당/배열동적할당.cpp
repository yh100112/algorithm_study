#include<iostream>
using namespace std;

int main(){
    //1.
    int* pnum = new int[2];
    delete[] pnum;

    //2.
    int num=3;
    float* pfloat = nullptr; // 포인터변수를 초기화할 때 사용 nullptr
    pfloat = new float[num];
    for(int i=0; i<num; i++){
        pfloat[i] = i+1.1;
        cout << pfloat[i] <<endl;
    }
    delete[] pfloat;

    //3.동적할당을 만든 배열은 (malloc이나 new로 생성한 것) 길이를 알 수 없다. 필요시마다 입력한 값을 사용해야한다.
    double* pdouble{new double[5]};
    delete[] pdouble;

    return 0;
}
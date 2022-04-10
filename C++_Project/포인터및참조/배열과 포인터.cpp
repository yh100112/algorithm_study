#include<iostream>
using namespace std;

int main(){
  int arr[3] = {100,200,300};
  int* ptr_arr = arr; //배열의 이름자체가 배열의 시작주소를 가리키는 주소값이므로 이렇게만 씀 (&arr 아님!)

  cout << "배열의 이름을 이용하여 배열 요소에 접근 : " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;
  cout << "포인터를 이용하여 배열 요소에 접근 : " << ptr_arr[0] << ", " << ptr_arr[1] << ", " << ptr_arr[2] << endl;
  cout << "배열의 이름을 이용한 배열의 크기 계산 : " << sizeof(arr) << endl; // 12
  cout << "포인터를 이용한 배열의 크기 계산 : " << sizeof(ptr_arr) << endl; // 8
  cout << ptr_arr << " "<<arr<<endl; // 배열 arr의 시작주소
  cout << *ptr_arr << endl; // 배열arr의 시작주소에 있는 값 : 100 그냥 배열이름 부른거랑 같다.

  int p[] = {10,20,30};
  int *pp = p;

  cout << "*pp + 1 : "  <<*pp + 1 << endl; // 11
  cout << "*(pp + 1) : "  <<*(pp + 1) << endl; // 20  pp는 배열p의 시작주소이므로 그 주소값에 +1은 하면 int크기만큼 넘어가서 거기의 주소값이 되므로 그 주소에 있는 값인 20이 나온다.
  
  return 0;
}
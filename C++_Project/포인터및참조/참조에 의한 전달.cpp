#include<iostream>
using namespace std;

void Local(int&);

int main(){
	int var = 10;
	cout << "변수var의 초기값 : " << var << endl;
	
	Local(var);
	cout << "Local()함수 호출 후 변수 var의 값 : "<< var << endl;
	return 0;
}

void Local(int& num){
	cout << num << endl; // 10
	num += 10;
}
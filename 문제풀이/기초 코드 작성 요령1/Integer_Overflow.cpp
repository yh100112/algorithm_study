#include<iostream>
using namespace std;

void func1(){
  for(char s = 0; s < 128; s++){
    cout << "hi" << endl;
  }
}

int func2(){
  int r = 1;
  for(int i = 1; i <= 50; i++){
    r = r * i % 61;
  }
  return r;
}

int func3(){
  int a = 10;
  int mod = 1000000007;
  for(int i = 0; i < 10; i++){
    a = 10 * a % mod;
    // cout << a << endl;
  }
  return a;
}

int main(){
  func3();
}

/*
integer overflow�� �߻��ϴ� ����?
-> func1, func3

func1�� ���
-> s�� 127�� �� �Ŀ� 1�� ������ �� -128�� �Ǳ� ������ �ǵ��Ѵ�� ��������
  �ʰ� ���ѷ����� ������. �̸� �ذ��Ϸ��� s�� �ڷ����� char���� int�� �ٲ�� �Ѵ�.

func3�� ���
-> i�� 9��° �� �� a�� 10��(10^9)�� * 10�� �ϹǷ� int�� ������ 21����     
  �Ѿ������ integer overflow�� �߻��Ѵ�.
  �̰� �������� a�� �ڷ����� long long���� �ٲٰų� 22��° �ٿ��� 10 ���
  10ll Ȥ�� (long long)���� ���� ����ȯ�� �Ͽ� �ذ��� �� �ִ�.
*/
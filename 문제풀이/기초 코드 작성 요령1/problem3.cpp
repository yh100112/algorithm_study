#include<iostream>
using namespace std;

int func3(int n){
  for(int i = 1; i * i <= n; i++){
    if(i * i == n) return 1;
  }
  return 0;
}

/*
����)
n�� �������̸� 1�� ��ȯ�ϰ� �������� �ƴϸ� 0�� ��ȯ�ϴ� �Լ� func3(int N)��
�ۼ��϶�. N�� 10�� ������ �ڿ����̴�.

func3(9) = 1
func3(693953651) = 0
func(756580036) = 1

�� ��� �ð����⵵�� i�� 1,2,... ��Ʈn���� ���� �Ǵ�
�ð����⵵�� O(��Ʈn)�� �ȴ�.
*/
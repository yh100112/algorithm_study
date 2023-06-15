#include<iostream>
#include<math.h>
using namespace std;

// ���� �� �ڵ�
// int func4(int n){
//   int max = 0;
//   for(int i = 0; pow(2,i) <= n; i++){
//     max = pow(2,i);
//   }
//   return max;
// }

// ��ŷ���� �� Ǯ��
int func4(int n){
  int val = 1;
  while(2 * val <= n){
    val *= 2;
  }
  return val;
}

int main(){
  cout << func4(97615282) << endl;
}

/*
����4)
N������ �� �߿��� ���� ū 2�� �ŵ��������� ��ȯ�ϴ� �Լ� func4(int n)�� �ۼ�
�϶�. N�� 10�� ������ �ڿ����̴�.

func4(5) = 4
func4(97615282) = 67108864

�ð����⵵
2^k <= N <= 2^k+1 �̶�� �� �� while�� �ȿ��� val�� �ִ� k����ŭ 2�辿 Ŀ�� ���̴�. �׷��Ƿ� �� �� �ð����⵵�� O(k)�̰� �ε�ȣ�� ��ü�� log�� ����� �α��� ���ǿ� �԰��ؼ� k�� logN�̴� �ð����⵵�� O(logN)�� �ȴ�.  
*/
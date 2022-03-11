#include<iostream>
#include<math.h>
using namespace std;

// 내가 한 코드
// int func4(int n){
//   int max = 0;
//   for(int i = 0; pow(2,i) <= n; i++){
//     max = pow(2,i);
//   }
//   return max;
// }

// 바킹독이 한 풀이
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
문제4)
N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int n)을 작성
하라. N은 10억 이하의 자연수이다.

func4(5) = 4
func4(97615282) = 67108864

시간복잡도
2^k <= N <= 2^k+1 이라고 할 때 while문 안에서 val는 최대 k번만큼 2배씩 커질 것이다. 그러므로 이 때 시간복잡도가 O(k)이고 부등호의 전체에 log를 씌우면 로그의 정의에 입각해서 k는 logN이니 시간복잡도는 O(logN)이 된다.  
*/
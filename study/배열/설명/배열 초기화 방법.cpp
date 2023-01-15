//배열의 전체를 초기화하는 방법

#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a[21];
  int b[21][21];

  // 1. memset
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  /*
  memset은 실수할 여지가 매우 많다.
  예를 들어 0이나 -1이 아닌 다른 값을 넣으면 오동작한다거나, 2차원 이상의
  배열을 함수의 인자로 넘겨 그 곳에서 memset을 하면 잘못 들어간다거나 하는
  점들이 있다.

  => memset은 매우 비추천
  */

  // 2. for
  for(int i = 0; i < 21; i++)
    a[i] = 0;
  for(int i = 0; i < 21; i++)
    for(int j = 0; j < 21; j++)
      b[i][j] = 0;
  /*
  그냥 for문을 돌면서 값을 하나하나 다 바꾸는 방식
  코드가 투박하긴 하지만 실수할 여지가 없기 때문에 무난하고 좋다.
  */

  // 3. fill
  fill(a, a+21, 0);
  for(int i = 0; i < 21; i++){
    fill(b[i], b[i] + 21, 0);
  }
  /*
  algorithm 헤더의 fill 함수를 이용하는 것
  -> 실수할 여지도 별로 없고 코드도 짧으니 익숙해진다면 가장 추천하는 방식
  */

}
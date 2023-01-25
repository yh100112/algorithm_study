#include<iostream>
using namespace std;

// 높이 : n, 밑변 : 2n - 1
char map[3072][6144];

void R(int x, int y, int n){
  if(n == 3) {
    // 더 이상 쪼개질 수 없으므로 별을 그림.
    map[x][y] = '*'; // 첫째줄
    map[x + 1][y - 1] = '*'; // 둘째줄
    map[x + 1][y + 1] = '*';
    for(int j = y - 2; j <= y + 2; j++) // 셋째줄
      map[x + 2][j] = '*';
    return;
  }

  // 그림을 보고 다음 삼각형을 그릴 시작 인덱스 x, y를 새롭게 설정
  R(x, y, n / 2); // 위 삼각형
  R(x + n / 2, y - n / 2, n / 2); // 아래 왼쪽 삼각형
  R(x + n / 2, y + n / 2, n / 2); // 아래 오른쪽 삼각형
}


int main(){
  int n;
  cin >> n;

  // map을 ' '로 초기화
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 2*n; j++)
      map[i][j] = ' ';
  
  R(0, n - 1, n); // 제일 위에 시작지점이 0, n-1이므로.

  // map 출력
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n * 2 - 1; j++) {
      cout << map[i][j];
    }
    cout << "\n";
  }
}
/*
입력값으로 24가 들어왔을 때의 패턴 : 프랙탈 구조
n == 24의 삼각형 : n == 12의 삼각형 3개로 구성
n == 12의 삼각형 : n == 6의 삼각형 3개로 구성
n == 6의 삼각형 : n == 3의 삼각형 3개로 구성
n == 3의 삼각형 : 더 이상 쪼개질 수 없는 가장 작은 삼각형
-> 삼각형을 그릴 시작 좌표와 n의 크기를 매개변수로 재귀함수를 시작해서 n == 3일 때까지 계속 쪼개가면서 삼각형을 그리도록 구현
*/
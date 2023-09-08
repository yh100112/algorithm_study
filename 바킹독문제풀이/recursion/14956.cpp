/*
Programming land의 범위를 4개의 범위로 나누어
walk를 바탕으로 현재 철학자가 어느 사분면에 존재하는지 파악한 후,
적절한 계산을 통해 사각형을 축소시키며 좌표값을 계산합니다.
*/
#include<iostream>
#include<utility>
using namespace std;
#define X first
#define Y second

// 한 변의 길이, 걸어간 거리로 x,y좌표를 재귀적으로 구하는 함수
pair<int,int> philo(int side, int walk){
  if(side == 2) {
    switch(walk) {
      case 1:
        return {1,1};
      case 2:
        return {1,2};
      case 3:
        return {2,2};
      case 4:
        return {2,1};
    }
  }
  // walk가 4분면 중 어디에 해당되는지에 따라 구분
  int half = side / 2;
  int section = half * half;
  if(walk <= section){
    pair<int,int> rv = philo(half, walk);
    return {rv.Y, rv.X}; // 90도로 회전하므로 x,y좌표 바꿔줌
  }
  else if(walk <= 2 * section){
    pair<int,int> rv = philo(half, walk - section);
    return {rv.X, rv.Y + half};
  }
  else if(walk <= 3 * section){
    pair<int,int> rv = philo(half, walk - (2 * section));
    return {rv.X + half,rv.Y + half};
  }
  else{
    pair<int,int> rv = philo(half, walk - (3 * section));
    return {2 * half - rv.Y + 1, half - rv.X + 1}; // 이 식 어떻게 구하는지 모르겠음
  }
}

int main(){
  int side,walk;
  cin >> side >> walk;
  pair<int,int> ans = philo(side, walk);
  cout << ans.X << " " << ans.Y;
}
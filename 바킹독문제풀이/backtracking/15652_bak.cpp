#include<iostream>
using namespace std;

int n,m;
int arr[10];

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << "\n";
  }

  int st = 1;
  if(k != 0) st = arr[k-1];
  for(int i = st; i <= n; i++){ // 이런 식으로 포문의 시작점을 바꿔주는 접근이 재귀를 푸는데 좋아보임
    arr[k] = i;
    func(k+1);
  }
}

int main() {
  cin >> n >> m;
  func(0);
}
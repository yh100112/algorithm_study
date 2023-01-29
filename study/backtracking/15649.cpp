#include<iostream>
using namespace std;

int n,m;
int arr[10]; // 수열을 담을 배열
bool isused[10]; // 특정 수가 쓰였는지를 true or false로 나타내는 배열

// 현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수
void func(int k){ 
	if(k == m){ // m개를 모두 택했으면 arr에 기록해둔 수를 출력하고 종료 ( Base condition )
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i = 1; i <= n; i++){ // 1부터 n까지의 수에 대해
    if(!isused[i]){ // 아직 i가 사용되지 않았으면
      arr[k] = i; // k번째 수를 i로 정함
      isused[i] = 1; // i를 사용되었다고 표시
      for(int c = 0; c < 2; c++)
        cout << arr[c] << " ";
      cout << " / " << k << endl;
      func(k+1); // 다음 수를 정하러 한 단계 더 들어감
      isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
    }
  }
}

// 1부터 n 까지 자연수 중 중복 없이 m개를 고른 수열
// 자연수 n 과 m
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}
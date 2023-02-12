#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
int arr[10];
int num[10];

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' ';
    cout << "\n";
    return;
  }

  int st = 0;
  if(k > 0) st = arr[k-1]; // 이거 이해가 정말 안되네... 재귀는 역시 어렵다 하아... 될때까지!!
  for(int i = st; i < n; i++){
    arr[k] = i;
    func(k+1);
  }
}

vector<int> chk(10002);

int main(){
  cin >> n >> m;
  int idx = 0;
  while(n--){
    int input;
    cin >> input;
    if(chk[input] == 1) continue;
    chk[input] = 1;
    num[idx] = input;
    idx++;
  }
  n = idx;
  sort(num, num+n);
  func(0);
}

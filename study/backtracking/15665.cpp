#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
int arr[10];
int num[10];

void func(int k){
  if(k == m){
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 0; i < n; i++){
    arr[k] = i;
    func(k+1);
  }
}

vector<bool> check(10002);

int main(){
  int i,j;
  cin >> n >> m;

  int input;
  int idx = 0;
  while(n--){
    cin >> input;
    if(check[input] == 1) continue;
    check[input] = 1;
    num[idx] = input;
    idx++;
  }
  n = idx;
  sort(num,num+n);
  func(0); //계속 0이 나옴
}
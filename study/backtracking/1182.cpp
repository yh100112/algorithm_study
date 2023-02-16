#include<iostream>
using namespace std;

int n,s;
int num[30];
int arr[30];
int isused[30];
int cnt;

void func(int k, int m){
  if(k == m){
    int sum = 0;
    for(int i = 0; i < m; i++)
      sum += num[arr[i]];
    if(sum == s) {
      cout << "m : " << m << endl;
      cnt++;
    }
    return;
  }

  for(int i = 0; i < n; i++){
    if(!isused[i]){
      isused[i] = 1;
      arr[k] = i;
      func(k+1,m);
      isused[i] = 0;
    }
  }
}

int main(){
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  for(int i = 0; i < n; i++)
    func(0,i+1);
  cout << cnt;
}
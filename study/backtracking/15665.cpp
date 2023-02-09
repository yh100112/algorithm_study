#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
int arr[10];

void func(int k, vector<int>& num){
  if(k == m){
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 0; i < n; i++){
    arr[k] = i;
    func(k+1, num);
  }
}

int main(){
  int i,j;
  vector<int> num;
  cin >> n >> m;
  for(i = 0; i < n; i++) {
    int input;
    cin >> input;
    if(i != 0){
      for(j = 0; j < i; j++){
        if(input == num[j])
          break;
      }
      if (j == i)
        num.push_back(input);
    }
    else{
      num.push_back(input);
    }
  }
  sort(num.begin(),num.end());
  func(0,num); //계속 0이 나옴
}
#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int arr[504][504]; // 높이

// 쌓는 것 : 1초, 빼는 것 : 2초
int main(){
  cin >> n >> m >> b;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  int mn = 2100000000;
  int height_ret = 0;
  for(int h = 0; h <= 256; h++) {
    int remove = 0;
    int build = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(h < arr[i][j]) remove += (arr[i][j] - h);
        else build += (h - arr[i][j]);
      }
    }
    if(remove + b >= build){
      int time = remove * 2 + build;
      if(time < mn) {
        mn = time;
        height_ret = h;
      }
    }
  }
  cout << mn << " " << height_ret << "\n";
}
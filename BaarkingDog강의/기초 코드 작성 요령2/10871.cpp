#include<iostream>
using namespace std;

//내가 짠 것
// int main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   int x,y;
//   cin >> x >> y;
//   int a[x];
//   for(int i = 0; i < x; i++){
//     cin >> a[i];
//   }

//   for(int i = 0; i < x; i++){
//     if(a[i] < y){
//       cout << a[i] << " ";
//     }
//   }
// }

//바킹독이 짠 것
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x,t;
  cin >> n >> x;
  while(n--){
    cin >> t;
    if(t < x) cout << t << " ";
  }
}

/*
sync,cin.tie를 썼을 때와 안썼을 때 온라인저지에서 채점된 속도는 0ms, 4ms로 
sync,cin.tie를 썼을 때가 더 빠르다.
*/
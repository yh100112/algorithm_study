#include<iostream>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y;
  int a[x];
  for(int i = 0; i < x; i++){
    cin >> z;
    a[i] = z;
  }

  for(int i = 0; i < x; i++){
    if(a[i] < y){
      cout << a[i] << " ";
    }
  }
}
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b){
  return a > b; // a가 b보다 클 때 우선적으로 출력하도록 함 (내림차순)
}

int main(){
  int a[10] = {9,3,5,4,1,10,8,6,7,2};
  sort(a, a+10,compare);
  for(int i = 0; i < 10; i++){
    printf("%d ",a[i]);
  }
}
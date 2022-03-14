#include<bits/stdc++.h>
using namespace std;


//내가 짠 코드
/*
int card[21] = {-100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(void){
  int a,b;
  int range;
  for(int i = 0; i < 10; i++){
    cin >> a >> b;

    if(b - a == 0) continue;
    else{
      range = (b-a + 1) / 2;
      for(int j = 0; j < range; j++){
        swap(card[a++], card[b--]);
      }
    }
  }

  for(int i = 1; i <= 20; i++){
    cout << card[i] << " ";
  }
}
*/

//바킹독 코드 ( stl reverse() 사용)
int num[21];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <= 10; i++){
    int a,b;
    cin >> a >> b;
    reverse(num + a, num + b + 1);
  }

  for(int i = 1; i <= 20; i++) cout << num[i] << " ";
}






















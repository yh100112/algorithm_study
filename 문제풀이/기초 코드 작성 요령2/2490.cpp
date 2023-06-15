#include<bits/stdc++.h>
using namespace std;

//내가 짠 코드
/*
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int yut[12];
  for(int i = 0 ; i < 12; i++){
    cin >> yut[i];
  }

  int i = 0;
  int zero = 0;
  while(i < 12){
    if(yut[i] == 0) zero++;
    if((i+1) % 4 == 0)
    {
      switch (zero)
      {
        case 1:
          cout << "A\n";
          break;
        case 2:
          cout << "B\n";
          break;
        case 3:
          cout << "C\n";
          break;
        case 4:
          cout << "D\n";
          break;
        case 0:
          cout << "E\n";
          break;
      }
      zero = 0;
    }
    i++;
  }
}
*/

//바킹독 코드
int result, input;
string res = "DCBAE";

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int r = 0; r < 3; r++) {
    result = 0;
    for(int c = 0; c < 4; c++) {
      cin >> input;
      result += input;
    }
    cout << res[result] << '\n';
  }
}
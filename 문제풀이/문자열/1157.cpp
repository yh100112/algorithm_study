#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string in;
  cin >> in;

  transform(in.begin(), in.end(), in.begin(), ::toupper);
  int check[26] = {0,};

  for(int i = 0; i < in.length(); i++){
    check[in[i] - 'A']++;
  }

  int mx = 0;
  int chk = 0;
  int target;
  for(int i = 0; i < 26; i++)
  {
    if(mx < check[i])
    {
      mx = max(mx, check[i]);
      chk = 0;
      target = i;
    }
    else {
      if(mx == check[i])
        chk = 1;
    }
  }

  if(chk == 1) {
    cout << "?";
  }
  else {
    cout << (char)toupper(target + 'A');
  }
  
  
}
#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
  if(a.length() != b.length()){
    return a.length() < b.length();
  }
  else if(a.length() == b.length())
  {
    int sumA = 0;
    int sumB = 0;
    for(int i = 0; i < a.length(); i++){
      if(a[i] >= '0' && a[i] <= '9'){
        sumA += a[i] - '0';
      }
    }
    for(int i = 0; i < b.length(); i++){
      if(b[i] >= '0' && b[i] <= '9'){
        sumB += b[i] - '0';
      }
    }

    if(sumA < sumB) return 1;
    else if(sumA == sumB) return a < b;
    else return 0;
  }
}

int main(){
  int n;
  string serial[50];
  scanf("%d",&n);

  for(int i = 0; i < n; i++){
    cin >> serial[i];
  }

  sort(serial,serial + n,compare);

  for(int i = 0; i < n; i++){
    cout << serial[i] << endl;
  }


}
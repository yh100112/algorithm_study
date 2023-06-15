#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int k,n;
vector<int> a;

int main(){
  cin >> k;
  for(int i = 0; i < k; i++){
    cin >> n;
    if(n == 0){
      a.pop_back();
    }
    else {
      a.push_back(n);
    }
  }
  cout << accumulate(a.begin(),a.end(), 0) << "\n";
}
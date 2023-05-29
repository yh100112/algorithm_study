#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<string> ans;
  for(int i = 0; i < n; i++){
    string a;
    getline(cin, a);
    ans.push_back(a);
  }
  for(auto& v: ans){
    cout << v.front() << v.back() << endl;
    // cout << v[0] << v[v.length()-1] << '\n';
  }
}
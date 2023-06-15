#include<iostream>
#include<vector>
using namespace std;
int n,x,y;
vector<pair<int,int>> v;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    v.push_back({x,y});
  }
  for(int i = 0; i < n; i++){
    int x = v[i].first;
    int y = v[i].second;
    int cnt = 0;
    for(int j = 0; j < n; j++){
      if(v[j].first > x && v[j].second > y){
        cnt++;
      }
    }
    cout << cnt + 1 << " ";
  }
  cout << endl;
}
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int dist[100001];
int n,k;
int main() {
  cin >> n >> k;
  fill(dist, dist+100001,-1);
  queue<int> Q;
  dist[n] = 0;
  Q.push(n);
  while(dist[k] == -1){
    auto cur = Q.front(); Q.pop();
    for(int nx : {cur - 1, cur + 1, cur * 2}) {
      if(nx < 0 || nx > 100001) continue;
      if(dist[nx] != -1) continue;
      dist[nx] = dist[cur] + 1; 
      Q.push(nx);
    }
  }
  cout << dist[k];
  return 0;
}


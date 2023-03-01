#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int dist[100002];

int main(){
  int n,k;
  cin >> n >> k; // 수빈 : n, 동생 : k
  fill(dist,dist + 100002, -1);

  queue<int> Q;
  Q.push(n);
  dist[n] = 0;

  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    for(auto nx: {cur-1, cur+1, 2 * cur}){
      if(nx < 0 || nx > 100001) continue;
      if(dist[nx] != -1) continue;
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  cout << dist[k];
}
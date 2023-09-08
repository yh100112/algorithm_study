#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int dist[1000002];
int f,s,g,u,d;

int main(){
  cin >> f >> s >> g >> u >> d;
  fill(dist, dist+1000002, -1);

  dist[s-1] = 0;
  queue<int> Q;
  Q.push(s-1);
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(auto& next: {cur + u, cur - d}) {
      if(next > f || next < 0) continue; // next가 0보다 아래인 경우도 따져줘야 함
      if(dist[next] != -1) continue;
      dist[next] = dist[cur] + 1;
      Q.push(next);
    }
  }
  if(dist[g-1] == -1)
    cout << "use the stairs";
  else
    cout << dist[g-1];
}



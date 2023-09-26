#include<bits/stdc++.h>
using namespace std;
const int _max = 100000;
int n, k, visited[_max + 4], cnt[_max + 4];
queue<int> q;

int main(){
    cin >> n >> k;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;

    while(q.size()){
        int cur = q.front();
        q.pop();
        for(auto next : {cur - 1, cur + 1, cur * 2}){
            if(next < 0 || next > _max) continue;
            if(!visited[next]){
                visited[next] = visited[cur] + 1;
                q.push(next);
                cnt[next] += cnt[cur];
            }
            else if(visited[cur] + 1 == visited[next]){
                cnt[next] += cnt[cur];
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
}
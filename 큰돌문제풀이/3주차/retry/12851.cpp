#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, k, cnt[MAX+4], visited[MAX+4];

int main(){
    cin >> n >> k;
    if(n == k){
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    cnt[n] = 1;
    while(q.size()){
        int cur = q.front(); q.pop();
        for(int next : {cur-1, cur+1, cur*2}){
            if(0 <= next && next <= MAX){
                if(!visited[next]){
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                    cnt[next] += cnt[cur]; 
                }
                else if(visited[next] == visited[cur] + 1){
                    cnt[next] += cnt[cur];
                }
            }
        }
    }
    cout << visited[k] - 1 << "\n";
    cout << cnt[k] << "\n";
}
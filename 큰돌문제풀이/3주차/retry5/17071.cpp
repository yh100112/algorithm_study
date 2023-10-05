#include<bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, visited[2][MAX + 4], cnt = 1, ok;
queue<int> q;

int main(){
    cin >> n >> k;
    if(n == k){cout << 0 << '\n'; return 0;}
    visited[0][n] = 1;
    q.push(n);

    while(true){
        k += cnt;

        if(k > MAX) break;
        if(visited[cnt % 2][k]){
            ok = 1;
            break;
        }
        
        int size = q.size();
        for(int i = 0; i < size; i++){
            int cur = q.front();
            q.pop();
            for(auto next : {cur - 1, cur + 1, cur * 2}){
                if(next < 0 || next > MAX || visited[cnt % 2][next]) continue;
                visited[cnt % 2][next] = visited[(cnt + 1) % 2][cur] + 1; 
                q.push(next);
                if(next == k){
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) break;
        cnt++;
    }
    if(ok) cout << cnt << '\n';
    else cout << -1 << '\n';
}
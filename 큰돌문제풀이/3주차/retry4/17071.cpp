#include<bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, turn;
bool ok = false;
int visited[2][MAX + 4];
queue<int> q;

int main(){
    cin >> n >> k;
    if(n == k){ cout << 0 << '\n'; return 0; }
    visited[0][n] = 1;
    q.push(n);

    while(true){
        turn++; // 1
        k += turn;
        if(k > MAX) break;
        if(visited[turn % 2][k]){
            ok = true;
            break;
        }

        int size = q.size();
        for(int i = 0; i < size; i++){
            int cur = q.front(); q.pop();
            for(auto next : {cur - 1, cur + 1, cur * 2}){
                if(next < 0 || next > MAX || visited[turn % 2][next]) continue;
                visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;
                q.push(next);

                if(k == next){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }

    if(ok) cout << turn << '\n';
    else cout << -1 << '\n';
}
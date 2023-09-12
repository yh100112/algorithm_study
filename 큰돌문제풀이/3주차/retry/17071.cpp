#include<bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, turn = 1, ok;
int visited[2][MAX + 4];

int main(){
    cin >> n >> k; // 수빈, 동생
    if(n == k){cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][n] = 1;
    q.push(n);

    int cnt = 0;
    while(!q.empty()){
        k += turn;
        if(k > MAX) break;
        if(visited[turn % 2][k]){
            ok = 1;
            break;
        }

        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            int here = q.front(); q.pop();
            for(auto next : {here - 1, here + 1, here * 2}){
                if(next < 0 || next > MAX || visited[turn % 2][next]) continue;
                visited[turn % 2][next] = visited[(turn+1) % 2][here] + 1;
                q.push(next);

                if(next == k){
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
}
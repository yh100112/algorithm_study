#include<bits/stdc++.h>
using namespace std;
const int _max = 500000;
bool ok;
int n, k, turn = 1;
int visited[2][_max + 4];
queue<int> q;

int main(){
    cin >> n >> k;
    if(n == k) {cout << 0 << '\n'; return 0;}
    visited[0][n] = 1; // 짝
    q.push(n);

    while(true){
        k += turn;
        if(k > _max) break;
        if(visited[turn % 2][k]){
            ok = true;
            break;
        }
        int size = q.size();
        for(int i = 0; i < size; i++){
            auto cur = q.front();
            q.pop();
            for(auto next : {cur - 1, cur + 1, cur * 2}){
                if(0 <= next && next <= _max){
                    if(!visited[turn % 2][next]){
                        visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;
                        q.push(next);
                        if(next == k){
                            ok = true;
                            break;
                        }
                    }
                }
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn << '\n';
    else cout << -1 << '\n';
}
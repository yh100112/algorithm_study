#include<bits/stdc++.h>
using namespace std;
const int max_n = 500000;
int visited[2][max_n + 4], a, b, ok, turn = 1;
// visited : 수빈이의 위치를 홀수초 짝수초 두가지로 나눈 것
// visited[0][x] : 짝수초 ( 0초, 2초, 4초, . . .)
// visited[1][x] : 홀수초 ( 1초, 3초, 5초, . . .)

int main(){
    cin >> a >> b;
    if(a == b){cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][a] = 1; // 처음 시작은 0초이므로 짝수에 거리가 들어감
    q.push(a);
    while(q.size()){
        b += turn; // 동생 이동
        if(b > max_n) break;
        // 동생 위치에 수빈이가 이미 동생이 방문하기 이전에 방문을 한 경우 체크 ( turn이 홀수면 홀수 짝수면 짝수여야 만날 수 있음 )
        if(visited[turn % 2][b]){
            ok = true;
            break;
        }

        // bfs에서 턴(거리)마다 구분해서 처리하도록 하기 위해 매번 큐사이즈를 새롭게 설정
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            int x = q.front(); q.pop();
            for(int nx : {x + 1, x - 1, x * 2}){
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue; // overflow체크, 방문했는지 체크
                
                // 수빈이가 2초에 방문했으면 다음은 3초에 방문하는 것이므로 turn + 1이 되는 것
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; 

                // 수빈이와 동생이 동시에 같은 곳에 도착해 만나는 경우 체크
                if(nx == b){
                    ok = 1; break;
                }
                q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
}
#include<bits/stdc++.h>
using namespace std;
const int max_n = 500000;
int visited[2][max_n + 4], a, b, ok, turn = 1;
// visited : 수빈이의 위치를 홀수 짝수 두가지로 나눈 것
int main(){
    cin >> a >> b;
    if(a == b){cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][a] = 1; //  수빈이가 동생 위치에 이미 방문했는지 안했는지를 체크하는 배열 ( 홀,짝으로 나뉨 )
    q.push(a);
    while(q.size()){
        b += turn; // 동생 이동
        if(b > max_n) break;
        // 동생 위치에 수빈이가 이미 방문을 한 경우 체크
        // turn이 홀수면 홀수 짝수면 짝수 체크 -> 둘다 같아야 만날 수 있음
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
                
                // 수빈이가 2초에 방문했으면 다음은 3초에 방문하는 것이므로 turn + 1이 되는 것 -> 홀짝으로 구분하기 떄문
                // 이해가 안되는데?...
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1; 

                // 수빈이와 동생이 같이 가면서 만나는 경우 체크
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
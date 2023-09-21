#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, h, a, b, ret = INF, visited[34][34];

bool check(){
    // 세로선
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){ // 가로선
            if(visited[j][start]) start++;
            else if(visited[j][start - 1]) start--;
        }
        if(i != start) return false;
    }
    return true;
}

void go(int idx, int cnt){
    if(cnt > 3 || ret <= cnt) return;
    if(check()){
        ret = min(ret, cnt);
        return;
    }

    // 가로선
    for(int i = idx; i <= h; i++){
        for(int j = 1; j <= n; j++){ // 세로선
            if(visited[i][j - 1] || visited[i][j] || visited[i][j + 1]) continue;
            visited[i][j] = 1;
            go(i + 1, cnt + 1); // 내가 틀린 부분 -> i + 1로 하게 되면 같은 가로선 번호에 넣는 선의 세로 위치별로 경우를 따질 수가 없음
            visited[i][j] = 0;
        }
    }
}

int main(){
    cin >> n >> m >> h; // 세로선의 개수, 가로선의 개수, 세로선마다 가로선을 놓을 수 있는 위치의 개수
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        visited[a][b] = 1; // a가로선 위치에서 세로 b -> b+1 쪽으로 가로선이 연결되어 있다는 의미
    }
    go(1, 0);
    cout << (ret == INF ? -1 : ret) << '\n';
}
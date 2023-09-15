#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, h, a, b, visited[34][14], ret = INF;

bool check(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][start]) start++;
            else if(visited[j][start-1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}

void go(int idx, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret, cnt);
        return;
    }
    // 가로
    for(int i = idx; i <= h; i++){
        for(int j = 1; j <= n; j++){
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
}

int main(){
    cin >> n >> m >> h; // 세로선, 가로선, 세로선마다 가로선을 놓을 수 있는 위치의 개수
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        visited[a][b] = 1; // a번 가로 위치에 b -> b+1 세로선쪽으로 가로선이 있다는 의미
    }
    go(1, 0);
    cout << (ret == INF ? -1 : ret) << '\n';
}
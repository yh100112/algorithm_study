#include<bits/stdc++.h>
using namespace std;
const int INF = -987654321;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, visited[54][54], ret = INF;
char a[54][54];

int bfs(int y, int x){
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y,x});

    int _max = INF;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
            _max = max(_max, visited[ny][nx]);
        }
    }
    return _max;
}

void go(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != 'L') continue;
            fill(&visited[0][0], &visited[0][0] + 54*54, 0);
            ret = max(ret, bfs(i,j));
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    go();
    cout << ret - 1 << '\n';
}
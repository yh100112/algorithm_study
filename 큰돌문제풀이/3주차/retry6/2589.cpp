#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
const int INF = -987654321;
int n, m, visited[54][54], ret;
char a[54][54];

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = 1;

    while(q.size()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 'W') continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[curY][curX] + 1;
            q.push({ny,nx});
            ret = max(ret, visited[ny][nx]);
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L'){
                fill(&visited[0][0], &visited[0][0] + 54*54, 0);
                bfs(i, j);
            }
        }
    }
    cout << ret - 1 << '\n';
}
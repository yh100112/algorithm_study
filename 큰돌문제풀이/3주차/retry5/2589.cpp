#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, visited[54][54], ret = -987654321;
char board[54][54];

void bfs(int a, int b){
    queue<pair<int,int>> q;
    visited[a][b] = 1;
    q.push({a,b});

    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        ret = max(ret, visited[y][x]);
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(board[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'L'){
                fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
                bfs(i, j);
            }
        }
    }
    cout << ret - 1 << '\n';
}
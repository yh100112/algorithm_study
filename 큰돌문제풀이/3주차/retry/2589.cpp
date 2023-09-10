#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, visited[54][54], ret = INT_MIN;
char a[54][54];
vector<pair<int,int>> land;

void bfs(int y, int x){
    fill(&visited[0][0] , &visited[0][0] + 54 * 54, 0);
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y,x});

    int _max = INT_MIN;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second  + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[cur.first][cur.second] + 1;
            q.push({ny,nx});
            _max = max(_max, visited[ny][nx]); 
        }
    }
    ret = max(_max, ret);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L') land.push_back({i,j});
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'L') bfs(i,j);
    
    cout << ret - 1 << "\n";
}
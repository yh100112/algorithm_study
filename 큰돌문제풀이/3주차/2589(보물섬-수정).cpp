#include<bits/stdc++.h>
using namespace std;
int n, m, dist[54][54], result = INT_MIN;
char a[54][54];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void bfs(int y, int x){
    fill(&dist[0][0], &dist[0][0] + 54 * 54, -1);
    queue<pair<int,int>> q;
    q.push({y,x});
    dist[y][x] = 0;

    int _max = INT_MIN;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[ny][nx] < 0 && a[ny][nx] == 'L'){
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                q.push({ny,nx});
                _max = max(dist[ny][nx], _max);
            }
        }
    }
    result = max(_max,result);
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
            if(a[i][j] == 'L') bfs(i,j);
        }
    }
    cout << result;
}
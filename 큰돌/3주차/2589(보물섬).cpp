#include<bits/stdc++.h>
using namespace std;
int n, m, dist[54][54], result = INT_MIN;
char a[54][54];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>> land;

int dfs(pair<int,int> start, pair<int,int> end){
    fill(&dist[0][0], &dist[0][0] + 54 * 54, -1);
    queue<pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.first == end.first && cur.second == end.second) break;
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[ny][nx] < 0 && a[ny][nx] == 'L'){
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                q.push({ny,nx});
            }
        }
    }
    return dist[end.first][end.second];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L') land.push_back({i,j});
        }
    }
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < i; j++){
            auto start = land[i];
            auto end = land[j];
            int _max = dfs(start, end);
            result = max(result, _max);
        }
    }
    cout << result << "\n";
}
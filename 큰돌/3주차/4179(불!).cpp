#include<bits/stdc++.h>
using namespace std;
int r,c, visited[1004][1004], visited2[1004][1004];
char a[1004][1004];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
queue<pair<int,int>> q, q2;

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J'){
                visited[i][j] = 1;
                q.push({i,j});
            }
            if(a[i][j] == 'F'){
                visited2[i][j] = 1;
                q2.push({i,j});
            }
        }
    }

    // fire bfs
    while(!q2.empty()){
        pair<int,int> cur = q2.front(); q2.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(visited2[ny][nx] || a[ny][nx] == '#') continue;
            visited2[ny][nx] = visited2[cur.first][cur.second] + 1;
            q2.push({ny,nx});
        }
    }

    // jihoon bfs
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c){
                cout << visited[cur.first][cur.second] << "\n";
                return 0;
            }
            if(visited[ny][nx] || a[ny][nx] == '#') continue;
            if(visited[ny][nx] < visited2[ny][nx]){
                visited[ny][nx] = visited[cur.first][cur.second] + 1; 
                q.push({ny,nx});
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
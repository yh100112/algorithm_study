#include<bits/stdc++.h>
using namespace std;
int r,c, jihoon[1004][1004], fire[1004][1004];
char a[1004][1004];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
queue<pair<int,int>> q, q2;

int main(){
    cin >> r >> c;
    fill(&fire[0][0], &fire[0][0] + 1004*1004, INT_MAX);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J'){
                jihoon[i][j] = 1;
                q.push({i,j});
            }
            if(a[i][j] == 'F'){
                fire[i][j] = 1;
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
            if(fire[ny][nx] != INT_MAX || a[ny][nx] == '#') continue;
            fire[ny][nx] = fire[cur.first][cur.second] + 1;
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
                cout << jihoon[cur.first][cur.second] << "\n";
                return 0;
            }
            if(jihoon[ny][nx] || a[ny][nx] == '#') continue;
            if(fire[ny][nx] <= jihoon[cur.first][cur.second] + 1) continue;
            jihoon[ny][nx] = jihoon[cur.first][cur.second] + 1; 
            q.push({ny,nx});
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
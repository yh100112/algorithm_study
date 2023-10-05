#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r, c, visited_jh[1004][1004], visited_fire[1004][1004];
queue<pair<int,int>> q_jh, q_fire;
char a[1004][1004];

int main(){
    cin >> r >> c;
    fill(&visited_fire[0][0], &visited_fire[0][0] + 1004*1004, INF);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){
                visited_fire[i][j] = 1;
                q_fire.push({i,j});
            }
            if(a[i][j] == 'J'){
                visited_jh[i][j] = 1;
                q_jh.push({i,j});
            }
        }
    }

    // fire
    while(q_fire.size()){
        int y = q_fire.front().first;
        int x = q_fire.front().second;
        q_fire.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited_fire[ny][nx] != INF) continue;
            if(a[ny][nx] == '#') continue;
            visited_fire[ny][nx] = visited_fire[y][x] + 1;
            q_fire.push({ny,nx});
        }
    }

    // jihoon
    while(q_jh.size()){
        int y = q_jh.front().first;
        int x = q_jh.front().second;
        q_jh.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c){
                cout << visited_jh[y][x] << '\n';
                return 0;
            }
            if(visited_jh[ny][nx] || a[ny][nx] == '#') continue;
            if(visited_jh[y][x] + 1 < visited_fire[ny][nx]){
                visited_jh[ny][nx] = visited_jh[y][x] + 1;
                q_jh.push({ny,nx});
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
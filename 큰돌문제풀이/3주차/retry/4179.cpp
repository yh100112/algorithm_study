#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r, c, visited_fire[1004][1004], visited_jh[1004][1004];
char a[1004][1004];
queue<pair<int,int>> fire, jh;

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J') {
                visited_jh[i][j] = 1;
                jh.push({i,j});
            }
            if(a[i][j] == 'F') {
                visited_fire[i][j] = 1;
                fire.push({i,j});
            }
        }
    }
    if(fire.size() == 0)
        fill(&visited_fire[0][0], &visited_fire[0][0] + 1004*1004, INT_MAX);

    // fire
    while(fire.size()){
        auto cur = fire.front(); fire.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited_fire[ny][nx]) continue;
            if(a[ny][nx] == '#') continue;
            visited_fire[ny][nx] = visited_fire[cur.first][cur.second] + 1;
            fire.push({ny,nx});
        }
    }
    // jh
    while(jh.size()){
        auto cur = jh.front(); jh.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c){
                visited_jh[ny][nx] = visited_jh[cur.first][cur.second] + 1;
                cout << visited_jh[ny][nx] - 1 << "\n";
                return 0;
            }
            if(a[ny][nx] == '#') continue;
            if(!visited_jh[ny][nx] && visited_jh[cur.first][cur.second] + 1 < visited_fire[ny][nx]){
                visited_jh[ny][nx] = visited_jh[cur.first][cur.second] + 1;
                jh.push({ny,nx});
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
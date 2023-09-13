#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int R, C, day, swanY, swanX, y, x, swan_visited[1504][1504], water_visited[1504][1504];
char a[1504][1504];
queue<pair<int,int>> water, swan, water_temp, swan_temp;

void Qclear(queue<pair<int,int>>& q){
    queue<pair<int,int>> temp;
    swap(q, temp);
}
void water_melting(){
    while(water.size()){
        tie(y,x) = water.front();
        water.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || water_visited[ny][nx]) continue;
            if(a[ny][nx] == 'X') {
                a[ny][nx] = '.';
                water_temp.push({ny,nx});
                water_visited[ny][nx] = 1;
            }
        }
    }
}
bool move_swan(){
    while(swan.size()){
        tie(y,x) = swan.front();
        swan.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || swan_visited[ny][nx]) continue;
            swan_visited[ny][nx] = 1;
            if(a[ny][nx] == '.') swan.push({ny,nx});
            else if(a[ny][nx] == 'L') return true;
            else if(a[ny][nx] == 'X') swan_temp.push({ny,nx});
        }
    }
    return false;
}
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L') swanY = i, swanX = j;
            if(a[i][j] == '.' || a[i][j] == 'L'){
                water.push({i,j});
                water_visited[i][j] = 1;
            }
        }
    }
    swan_visited[swanY][swanX] = 1;
    swan.push({swanY, swanX});
    while(true){
        if(move_swan()) break;
        water_melting();
        swan = swan_temp;
        water = water_temp;
        Qclear(swan_temp);
        Qclear(water_temp);
        day++;
    }
    cout << day << "\n";
}
#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r, c, visited_swan[1504][1504], visited_water[1504][1504], day, swanX, swanY;
char a[1504][1504];
queue<pair<int,int>> swan, water, swan_temp, water_temp;

void QClear(queue<pair<int,int>>& q){
    queue<pair<int,int>> temp;
    swap(q, temp);
}

void water_melting(){
    while(water.size()){
        int y = water.front().first;
        int x = water.front().second;
        water.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited_water[ny][nx]) continue;
            visited_water[ny][nx] = 1;
            if(a[ny][nx] == 'L' || a[ny][nx] == '.') water.push({ny,nx});
            if(a[ny][nx] == 'X') water_temp.push({ny,nx}), a[ny][nx] = '.'; 
        }
    }
}

bool move_swan(){
    while(swan.size()){
        int y = swan.front().first;
        int x = swan.front().second;
        swan.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = 1;
            if(a[ny][nx] == 'L') return true;
            if(a[ny][nx] == '.') swan.push({ny,nx});
            if(a[ny][nx] == 'X') swan_temp.push({ny,nx});
        }
    }
    return false;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L') swanY = i, swanX = j;
            if(a[i][j] == '.' || a[i][j] == 'L') water.push({i,j}), visited_water[i][j] = 1;
        }
    }

    visited_swan[swanY][swanX] = 1;
    swan.push({swanY, swanX});

    while(true){
        if(move_swan()) break;
        water_melting();
        swan = swan_temp;
        water = water_temp;
        QClear(swan_temp);
        QClear(water_temp);
        day++;
    }
    cout << day << '\n';
}
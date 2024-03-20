#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int r, c, day, swanY, swanX;
char a[1504][1504];
queue<pair<int,int>> swan, water;
int visited_swan[1504][1504], visited_water[1504][1504];

void water_melt() {
    queue<pair<int,int>> temp;
    while(water.size()) {
        int y = water.front().first;
        int x = water.front().second;
        water.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_water[ny][nx]) continue;
            if (a[ny][nx] == 'X') {
                temp.push({ny,nx});
                a[ny][nx] = '.';
            }
            else
                water.push({ny,nx});
            visited_water[ny][nx] = 1;
        }
    }
    water = temp;
}

bool move_swan() {

    queue<pair<int,int>> temp;
    while(swan.size()) {
        int y = swan.front().first;
        int x = swan.front().second;
        swan.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx]) continue;
            if (a[ny][nx] == 'X') { // 이렇게 안 하면 시간초과남
                temp.push({ny,nx});
                visited_swan[ny][nx] = 1;
            }
            else if (a[ny][nx] == '.') {
                swan.push({ny,nx});
                visited_swan[ny][nx] = 1;
            }
            else
                return true;
        }
    }
    swan = temp;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'L')
                swanY = i, swanX = j;
            if (a[i][j] == '.' || a[i][j] == 'L') {
                water.push({i,j});
                visited_water[i][j] = 1;
            }
        }
    }

    visited_swan[swanY][swanX] = 1;
    swan.push({swanY,swanX});

    while(true){
        if(move_swan()) break;
        water_melt();
        day++;
    }
    cout << day << "\n";
}
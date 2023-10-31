#include<bits/stdc++.h>
using namespace std;
int dy[] = {0, -1 ,0, 1};
int dx[] = {1, 0, -1, 0};
int dy2[] = {0, 1 ,0, -1};
int dx2[] = {1, 0, -1, 0};
int r, c, t, a[54][54], temp[54][54], ret;
vector<pair<int,int>> air, m1, m2;

void mise_go(){
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] <= 0) continue;
            int spread = a[i][j] / 5;
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;
                temp[ny][nx] += spread;
                a[i][j] -= spread;
            }
        }
    }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            a[i][j] += temp[i][j];
}

void check(pair<int,int>& air, vector<pair<int,int>>& m, int dy[], int dx[]){
    int y = air.first;
    int x = air.second;
    int cur = 0;
    while(true){
        int ny = y + dy[cur];
        int nx = x + dx[cur];
        if(ny == air.first && nx == air.second) break;
        if(ny < 0 || ny >= r || nx < 0 || nx >= c){
            cur++;
            continue;
        }
        m.push_back({ny,nx});
        y = ny;
        x = nx;
    }
}

void move(vector<pair<int,int>>& m){
    for(int i = m.size() - 1; i > 0; i--){
        a[m[i].first][m[i].second] = a[m[i-1].first][m[i-1].second];
    }
    a[m[0].first][m[0].second] = 0;
}

int main(){
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == -1) air.push_back({i,j});
        }
    }
    check(air[0], m1, dy, dx);
    check(air[1], m2, dy2, dx2);
    
    while(t--){
        mise_go();
        move(m1);
        move(m2);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) {
            if(a[i][j] != -1) ret += a[i][j];
        }
    }
    cout << ret << '\n';
}
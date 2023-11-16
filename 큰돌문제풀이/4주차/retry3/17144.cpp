#include<bits/stdc++.h>
using namespace std;
int dy1[] = {0,-1,0,1}; // 반시계
int dx1[] = {1,0,-1,0};
int dy2[] = {0,1,0,-1}; // 시계
int dx2[] = {1,0,-1,0};
int n, m, t, a[54][54], temp[54][54], ret;
vector<pair<int,int>> air, pos1, pos2;

void spread(){
    fill(&temp[0][0], &temp[0][0] + 54*54, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == -1) continue;
            int y = i;
            int x = j;
            int num = a[y][x] / 5;
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                int ny = y + dy1[dir];
                int nx = x + dx1[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1) continue;
                temp[ny][nx] += num;
                cnt++;
            }
            a[y][x] -= (num * cnt);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            a[i][j] += temp[i][j];
        }
    }
}

// y,x : 시작위치
void moving(int dy[], int dx[], int startY, int startX, vector<pair<int,int>>& pos){
    pos.clear();
    int dir = 0;
    int y = startY;
    int x = startX;
    while(true){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m){
            dir++;
            ny = y + dy[dir % 4];
            nx = x + dx[dir % 4];
        }
        if(a[ny][nx] == -1) break;
        y = ny;
        x = nx;
        pos.push_back({y,x});
    }
}

void go(vector<pair<int,int>>& pos){
    for(int i = pos.size() - 1; i > 0; i--)
        a[pos[i].first][pos[i].second] = a[pos[i - 1].first][pos[i - 1].second];
    
    a[pos[0].first][pos[0].second] = 0;
}

int main(){
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == -1) air.push_back({i,j});
        }
    }

    while(t--){
        spread();
        moving(dy1, dx1, air[0].first, air[0].second, pos1);
        moving(dy2, dx2, air[1].first, air[1].second, pos2);
        go(pos1);
        go(pos2);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] != -1)
                ret += a[i][j];
    
    cout << ret << '\n';
}

/*
첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.
둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다. 공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다. -1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.
*/
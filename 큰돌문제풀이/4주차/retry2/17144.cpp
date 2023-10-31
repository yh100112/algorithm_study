#include<bits/stdc++.h>
using namespace std;
int dy[] = {0, -1 ,0, 1};
int dx[] = {1, 0, -1, 0};
int dy2[] = {0, 1 ,0, -1};
int dx2[] = {1, 0, -1, 0};
int r, c, t, a[54][54], temp[54][54], ret;
vector<pair<int,int>> air, m1, m2;

void spread(){
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++){
    //         if(a[i][j] > 0){
    //             for(int k = 0; k < 4; k++){
    //                 int ny = i + dy[k];
    //                 int nx = j + dx[k];
    //                 if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;
    //                 temp[ny][nx] += a[i][j] / 5;
    //                 a[i][j] -= a[i][j] / 5;
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i < r; i++)
    //     for(int j = 0; j < c; j++)
    //         a[i][j] += temp[i][j];
    queue<pair<int,int>> q; // 미세먼지 위치
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] != -1 && a[i][j])
                q.push({i, j});
        }
    }
    while(q.size()){
        int y,x;
        tie(y, x) = q.front();
        q.pop();
        int spread = a[y][x] / 5;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;
            temp[ny][nx] += spread;
            a[y][x] -= spread;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            a[i][j] += temp[i][j];
        }
    }
}

void check(pair<int,int>& air, vector<pair<int,int>>& m, int dy[], int dx[]){
    int y = air.first;
    int x = air.second;
    int cur = 0;
    // while(true){
    //     int ny = y + dy[cur];
    //     int nx = x + dx[cur];
    //     if(a[ny][nx] == -1) break;
    //     if(ny < 0 || ny >= r || nx < 0 || nx >= c){
    //         cur++;
    //         continue;
    //     }
    //     m.push_back({ny,nx});
    //     y = ny;
    //     x = nx;
    // }
    while(true){
        int ny = y + dy[cur];
        int nx = x + dx[cur];
        if(ny == air.first && nx == air.second) break; // 처음 지점(공기청정기)으로 돌아오면 종료
        if(ny < 0 || ny >= r || nx < 0 || nx >= c){ // 끝지점에 왔다면 방향 변경
            cur++;
            ny = y + dy[cur];
            nx = x + dx[cur];
        }
        if(ny == air.first && nx == air.second) break; // 처음 지점(공기청정기)으로 돌아오면 종료
        y = ny;
        x = nx;  
        m.push_back({ny,nx}); // 이동할 미세먼지 영역 위치좌표들 저장
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
    
    while(t--){
        spread();
        check(air[0], m1, dy, dx);
        check(air[1], m2, dy2, dx2);
        move(m1);
        move(m2);
    }

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            ret += a[i][j];
    cout << ret + 2 << '\n';
}
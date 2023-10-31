#include<bits/stdc++.h>
using namespace std;
int a[54][54], n, m, t, ret, temp[54][54];
int dy1[] = {0,-1,0,1};
int dx1[] = {1,0,-1,0};
int dy2[] = {0,1,0,-1};
int dx2[] = {1,0,-1,0};

void mise_go(int dy[], int dx[]){
    fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
    queue<pair<int,int>> q; // 미세먼지 위치
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
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
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1) continue;
            temp[ny][nx] += spread;
            a[y][x] -= spread;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] += temp[i][j];
        }
    }
    return;
}

vector<pair<int,int>> chung(int sy, int sx, int dy[], int dx[]){
    vector<pair<int,int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while(true){
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if(ny == sy && nx == sx) break; // 처음 지점(공기청정기)으로 돌아오면 종료
        if(ny < 0 || ny >= n || nx < 0 || nx >= m){ // 끝지점에 왔다면 방향 변경
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if(ny == sy && nx == sx) break;
        y = ny;
        x = nx;  
        v.push_back({ny,nx}); // 이동할 미세먼지 영역 위치좌표들 저장
    }
    return v;
}

void go(vector<pair<int,int>>& v){
    for(int i = v.size() - 1; i > 0; i--){
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    }
    a[v[0].first][v[0].second] = 0;
    return;
}

int main(){
    cin >> n >> m >> t;
    bool flag = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == -1){
                // 공기청정기 위쪽에 있는 이동할 미세먼지 영역
                if(flag){
                    v1 = chung(i, j, dy1, dx1);
                    flag = false;
                }
                // 공기청정기 아래쪽에 있는 이동할 미세먼지 영역
                else{
                    v2 = chung(i, j, dy2, dx2);
                }
            }
        }
    }
    while(t--){
        mise_go(dy1, dx1);
        go(v1);
        go(v2);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != -1) ret += a[i][j];
        }
    }
    cout << ret << "\n";
}
// 공기청정기!! -> 바람으로 이동하는 영역을 미리 뽑아놓는다.
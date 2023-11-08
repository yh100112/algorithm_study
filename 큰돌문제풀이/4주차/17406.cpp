#include<bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int INF = 987654321;
const int dy[] = {0,1,0,-1}; // 처음에 오른쪽으로 이동시키므로 우부터 시작
const int dx[] = {1,0,-1,0};
int n, m, k, a[104][104], b[104][104], ret = INF, r, c, s, visited[104][104], dir, sy, sx, ey, ex;
struct A{
    int y, x, cnt;
};
vector<A> v; // 돌리는 규칙
vector<int> v_idx; // 돌리는 규칙 순서
vector<pair<int,int>> vv; // 반시계방향으로 회전시킬 위치들 저장

void go(int y, int x, int first){
    if(!first && y == sy && x == sx) dir++;
    if(!first && y == sy && x == ex) dir++;
    if(!first && y == ey && x == ex) dir++;
    if(!first && y == ey && x == sx) dir++;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(visited[ny][nx]) return;
    visited[ny][nx] = 1;
    vv.push_back({ny,nx});
    go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt){
    // 한 area마다의 꼭짓점 네곳 ( sy, sx, ey, ex )
    for(int i = 1; i <= cnt; i++){
        sy = y - 1 * i; 
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;
        vv.clear();
        dir = 0;
        fill(&visited[0][0], &visited[0][0] + 104*104, 0);
        visited[sy][sx] = 1; // 현재 area에서 회전시킬 시작지점
        vv.push_back({sy,sx});
        go(sy, sx, 1);

        vector<int> vvv; // 반시계반향으로 회전시킬 위치들에 있는 값 저장
        for(pair<int,int> c : vv) vvv.push_back(b[c.f][c.s]);
        rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend()); // 시계방향으로 한칸씩 이동
        for(int i = 0; i < vv.size(); i++) b[vv[i].f][vv[i].s] = vvv[i];
    }
}

int solve(){
    for(int i : v_idx) rotateAll(v[i].y, v[i].x, v[i].cnt);
    int mn = INF;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++) cnt += b[i][j];
        mn = min(mn, cnt);
    }
    return mn;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < k; i++){
        cin >> r >> c >> s; r--; c--;
        v.push_back({r, c, s});
        v_idx.push_back(i);
    }
    do{
        memcpy(b, a, sizeof(a)); // 원본배열 a를 변경하지 않고 b라는 복사본을 사용
        ret = min(ret, solve());
    }while(next_permutation(v_idx.begin(), v_idx.end()));
    cout << ret << '\n';
}
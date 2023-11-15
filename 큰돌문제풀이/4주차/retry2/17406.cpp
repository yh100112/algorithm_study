#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, k, a[54][54], b[54][54], visited[54][54], ret = INF, dir = 1, sy, sx, ey, ex;
struct A{
    int r, c, cnt;
};
vector<A> v; // 회전 규칙
vector<int> v_idx;
vector<pair<int,int>> location;
vector<int> value;

void go(int y, int x, int flag){
    // if(!flag && y == sy && x == sx) dir++;
    if(!flag && y == sy && x == ex) dir++;
    if(!flag && y == ey && x == ex) dir++;
    if(!flag && y == ey && x == sx) dir++;

    int ny = y + dy[dir % 4];
    int nx = x + dx[dir % 4];
    if(visited[ny][nx]) return;
    location.push_back({ny,nx});
    value.push_back(b[ny][nx]);
    visited[ny][nx] = 1;
    go(ny, nx, 0);
}
void rotateAll(int r, int c, int cnt){
    fill(&visited[0][0], &visited[0][0] + 54*54, 0);
    for(int i = cnt; i > 0; i--){
        location.clear();
        value.clear();
        dir = 1;
        sy = r - i, sx = c - i;
        ey = r + i, ex = c + i;
        visited[sy][sx] = 1;
        location.push_back({sy,sx});
        value.push_back(b[sy][sx]);
        go(sy, sx, 1); // 회전 연산 한 껍질 수행 -> 해당 연산을 통해 돌리는 위치 저장

        rotate(value.rbegin(), value.rbegin() + 1, value.rend());
        for(int i = 0; i < location.size(); i++) 
            b[location[i].first][location[i].second] = value[i];
    }
}

int solve(){
    for(int i = 0; i < v.size(); i++) 
        rotateAll(v[v_idx[i]].r, v[v_idx[i]].c, v[v_idx[i]].cnt);
    int mn = INF;
    for(int i = 0; i < n; i++){
        int num = 0;
        for(int j = 0; j < m; j++)
            num += b[i][j];  
        mn = min(mn, num);
    }
    return mn;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < k; i++){
        int r,c,cnt;
        cin >> r >> c >> cnt;
        r--, c--;
        v.push_back({r,c,cnt});
        v_idx.push_back(i);
    }

    // 벡터 v의 순서가 뒤바뀜 ( 순열을 구해줌 )
    do{
        memcpy(b, a, sizeof(a));
        ret = min(ret, solve());
    }while(next_permutation(v_idx.begin(), v_idx.end()));
    cout << ret << '\n';
}
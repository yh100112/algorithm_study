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

int cnt;
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

void rotateAll(){
    fill(&visited[0][0], &visited[0][0] + 54*54, 0);
    for(auto idx : v_idx){
        int r = v[idx].r;
        int c = v[idx].c;
        int cnt = v[idx].cnt;

        // 회전연산 1개 수행
        for(int i = cnt; i > 0; i--){
            location.clear();
            value.clear();
            dir = 1;
            sy = r - i, sx = c - i;
            ey = r + i, ex = c + i;
            int y = sy;
            int x = sx;
            visited[y][x] = 1;
            location.push_back({y,x});
            value.push_back(b[y][x]);
            go(y, x, 1); // 회전 연산 한 껍질 수행

            rotate(value.rbegin(), value.rbegin() + 1, value.rend());
            for(int i = 0; i < location.size(); i++) 
                b[location[i].first][location[i].second] = value[i];
        }
    }
}

int solve(){
    for(int i = 0; i < v.size(); i++) rotateAll();
    int mn = INF;
    for(int i = 0; i < n; i++){
        int num = 0;
        for(int j = 0; j < n; j++)
            num += b[i][j];  
        mn = min(mn, num);
    }
    return mn;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < k; i++){
        int r,c,cnt;
        cin >> r >> c >> cnt;
        v.push_back({r,c,cnt});
        v_idx.push_back(i);
    }

    // 벡터 v의 순서가 뒤바뀜 ( 순열을 구해줌 )
    // do{
        memcpy(b, a, sizeof(a));
        ret = min(ret, solve());
    // }while(next_permutation(v_idx.begin(), v_idx.end()));
    // cout << ret << '\n';
}
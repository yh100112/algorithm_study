#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, r, l, a[54][54], visited[54][54], sum, cnt;
vector<pair<int,int>> v;

void bfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0|| ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        int diff = abs(a[ny][nx] - a[y][x]);
        if(l <= diff && diff <= r){
            sum += a[ny][nx];
            visited[ny][nx] = 1;
            v.push_back({ny,nx});
            bfs(ny,nx);
        }
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    while(true){
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    sum = a[i][j];
                    v.push_back({i,j});
                    bfs(i,j);
                    if(v.size() == 1) continue;
                    for(auto p : v)
                        a[p.first][p.second] = sum / v.size();
                    flag = 1;
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout << cnt << "\n";
}
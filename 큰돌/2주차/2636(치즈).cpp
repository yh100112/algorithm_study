#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, num, cnt, a[102][102], visited[102][102];
vector<pair<int,int>> v;

void dfs(int y, int x){
    visited[y][x] = 1;
    if(a[y][x] == 1){
        v.push_back({y,x});
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        dfs(ny,nx);
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
        v.clear();
        dfs(0,0);
        num = v.size();
        for(auto b : v){
            a[b.first][b.second] = 0;
        }

        int flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1) flag = 1;
            }
        }
        cnt++;
        if(flag == 0) break;
    }

    cout << cnt << "\n" << num << "\n";
}
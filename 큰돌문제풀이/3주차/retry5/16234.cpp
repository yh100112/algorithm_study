#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, l, r, a[54][54], visited[54][54], day;

int dfs(int y, int x, vector<pair<int,int>>& b){
    visited[y][x] = 1;
    int sum = a[y][x];
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r){
            b.push_back({ny,nx});
            sum += dfs(ny, nx, b);
        }
    }
    return sum;
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
                if(visited[i][j]) continue;
                vector<pair<int,int>> v;
                v.push_back({i,j});
                int sum = dfs(i, j, v);
                if(v.size() == 1) continue;
                for(auto c : v)
                    a[c.first][c.second] = sum / v.size();
                flag = 1;
            }
        }
        if(!flag) break;
        day++;
    }
    cout << day << '\n';
}
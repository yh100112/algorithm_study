#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, l, r, a[54][54], visited[54][54], sum, day;

void dfs(int y, int x, vector<pair<int,int>>& v){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(l >= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] = 1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            dfs(ny,nx,v);
        }
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    while(true){
        int flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    vector<pair<int,int>> v;
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    dfs(i,j,v);
                    if(v.size() == 1) continue;
                    for(auto p : v){
                        a[p.first][p.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) break;
        day++;
    }
    cout << day << '\n';
}
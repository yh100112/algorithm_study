#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, l, r, a[54][54], visited[54][54], day, sum;

void dfs(int y, int x, vector<pair<int,int>>& v){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if(l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r){
            v.push_back({ny,nx});
            visited[ny][nx] = 1;
            sum += a[ny][nx];
            dfs(ny, nx, v);
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
                if(visited[i][j]) continue;
                vector<pair<int,int>> b;
                sum = a[i][j];
                b.push_back({i,j});
                visited[i][j] = 1;
                dfs(i, j, b);
                if(b.size() == 1) continue;
                for(auto p : b)
                    a[p.first][p.second] = sum / b.size();
                flag = 1;
            }
        }
        if(!flag) break;
        day++;
    }
    cout << day << '\n';
}
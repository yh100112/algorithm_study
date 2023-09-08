#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int x,y,x2,y2;
int arr[102][102];
int visited[102][102];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x, int& num) {
    visited[y][x] = 1;
    num++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if(visited[ny][nx] == 1 || arr[ny][nx] == 1) continue;
        dfs(ny,nx,num);
    }
}

int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y >> x2 >> y2;
        for(int a = y; a < y2; a++)
            for(int b = x; b < x2; b++)
                arr[a][b] = 1;
    }
    int cnt = 0;
    vector<int> area;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0 && arr[i][j] == 0) {
                cnt++;
                int num = 0;
                dfs(i,j,num);
                area.push_back(num);
            }
        }
    }
    sort(area.begin(),area.end());
    cout << cnt << "\n";
    for(auto v: area)
        cout << v << " ";
    cout << "\n";
}
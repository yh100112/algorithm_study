#include<bits/stdc++.h>
using namespace std;
#define Y first
#define X second
int m,n,k,t,x,y,ret;
int arr[51][51];
int visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if(arr[ny][nx] == 0 || visited[ny][nx]) continue;
        dfs(ny,nx);
    }
}

int main(){
    cin >> t;
    while(t--){
        fill(&arr[0][0], &arr[0][0] + 51*51, 0);
        fill(&visited[0][0], &visited[0][0] + 51*51, 0);
        cin >> m >> n >> k;
        for(int b = 0; b < k; b++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] || arr[i][j] == 0) continue;
                ret++;
                dfs(i,j);
            }
        }
        cout << ret << endl;
        ret = 0;
    }
}
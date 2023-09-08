#include<bits/stdc++.h>
using namespace std;
int n, h;
int arr[101][101];
int visited[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx] == 0 && arr[ny][nx] > h) {
            dfs(ny,nx);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    // 높이 : 1 ~ 100
    int mx = 1; // 결과 -> 비가 안 올경우도 있음
    int num = 0;
    h = 0;
    while(h <= 100){
        fill(&visited[0][0], &visited[0][0] + 101*101, 0);
        num = 0;
        h++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] > h && visited[i][j] == 0) {
                    dfs(i,j);
                    num++;
                }
            }
        }
        mx = max(num, mx);
    }
    cout << mx;
}